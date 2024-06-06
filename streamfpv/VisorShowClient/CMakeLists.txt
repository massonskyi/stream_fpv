cmake_minimum_required(VERSION 3.14)

project(VisorShowClient LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia MultimediaWidgets Network)
find_package(OpenCV REQUIRED)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    find_library(WIRINGPI_LIB wiringPi)  # Поиск библиотеки wiringPi
endif()

include_directories(${PROJECT_SOURCE_DIR}/../GeneralIncludes)
include_directories(${PROJECT_SOURCE_DIR}/includes)

add_executable(VisorShowClient
    main.cpp
    includes/visorsubcription.h src/visorsubcription.cpp
    includes/visorcontroller.h src/visorcontroller.cpp
    includes/visorgui.h src/visorgui.cpp
    includes/cmd_utils.h src/cmd_utils.cpp
    includes/mergearray.h src/mergearray.cpp
    includes/localconstants.h
    includes/localcontrolstruct.h
    includes/imagewidget.h
    includes/networkmonitor.h

    ../GeneralIncludes/controlstructs.h
    ../GeneralIncludes/constants.h

)

target_link_libraries(VisorShowClient
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Network
    ${OpenCV_LIBS}
)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")  # Проверяем, что архитектура является ARM
    target_link_libraries(VisorShowClient
        "/usr/lib/libwiringPi.so"
    )
endif()
include(GNUInstallDirs)
install(TARGETS VisorShowClient
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
