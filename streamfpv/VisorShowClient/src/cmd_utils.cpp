#include "cmd_utils.h"

#include <iostream>
#include <regex>

namespace CmdUtils {

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::string join(const std::vector<std::string>& tokens, char delimiter){
    std::string ret = "";

    for(auto it = tokens.begin(); it != tokens.end(); it++){
        ret += *it + delimiter;
    }

    return ret.substr(0, ret.size()-1);
}

std::vector<Iface> get_iface(){
    std::vector<Iface> ifaces;

    std::string iface = "";
    std::string ip = "";
    std::string ip_lo = "";

    try{
        auto in = exec("ip a");
        int pos = in.find("BROADCAST,MULTICAST,UP");

        while (pos != std::string::npos) {
            int p_s = in.find(":", pos - 25);
            int p_e = in.find(":", p_s + 1);

            iface = in.substr(p_s + 2, p_e - p_s - 2);

            p_s = in.find("inet ", pos);
            if(p_s != std::string::npos){
                int p_e = in.find("/", p_s);
                ip = in.substr(p_s + 5, p_e - (p_s + 5));

                if(ip.size()){
                    auto splitted = split(ip, '.');
                    splitted.back() = "0";
                    ip_lo = join(splitted, '.');

                    // std::cout << ip << " " << ip_lo << std::endl ;
                }
            }

            ifaces.push_back({iface, ip, ip_lo});
            pos = in.find("BROADCAST,MULTICAST,UP", pos+1);
        }
    }catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    return ifaces;
}

std::vector<ArpInfo> arp_scan_parser(const std::string &parse_data){
    std::vector<ArpInfo> arp;
    try{
        std::regex reg("(\\d{1,3}(\\.\\d{1,3}){3})");

        auto lines = split(parse_data, '\n');
        std::smatch color_match;

        for(const auto &line : lines){
            if (std::regex_search(line, color_match, reg))
            {
                auto param = split(line, '\t');

                if (param.size() == 3){
                    arp.push_back({param.at(0),
                                   param.at(1),
                                   param.at(2)});
                }
            }
        }

    }catch(std::runtime_error &err){
        std::cout << err.what() << std::endl;
    }

    return arp;
}

std::vector<ArpInfo> arp_scan(const char *iface)
{
    try{
        auto ask = std::string("sudo arp-scan --interface=") + std::string(iface) + std::string(" --localnet");
        auto answer = exec(ask.c_str());
        return arp_scan_parser(answer);
    }catch(std::runtime_error &err){
        std::cout << err.what() << std::endl;
    }

    return {};
}

std::vector<ArpInfo> arp_scan(const char *ip_address, const char *mask)
{
    try{
        auto ask = std::string("sudo arp-scan ") + std::string(ip_address) + "/" + std::string(mask);
        auto answer = exec(ask.c_str());
        return arp_scan_parser(answer);
    }catch(std::runtime_error &err){
        std::cout << err.what() << std::endl;
    }
    return {};
}

}


