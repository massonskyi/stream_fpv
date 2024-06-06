#ifndef CMD_UTILS_H
#define CMD_UTILS_H

#include <string>
#include <vector>

namespace CmdUtils {

struct ArpInfo{
    std::string ip;
    std::string mac;
    std::string name;
};

struct Iface{
    std::string iface_name;
    std::string iface_ip;
    std::string iface_lo_ip;
};

std::vector<Iface> get_iface();
std::vector<ArpInfo> arp_scan(const char *iface);
std::vector<ArpInfo> arp_scan(const char *ip_address, const char *mask);

}

#endif // CMD_UTILS_H
