cmake_minimum_required(VERSION 3.14)

project(CameraCaptureServer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)
find_package(OpenCV REQUIRED)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    find_library(WIRINGPI_LIB wiringPi)  # Поиск библиотеки wiringPi
endif()

include_directories(${PROJECT_SOURCE_DIR}/../GeneralIncludes)
include_directories(${PROJECT_SOURCE_DIR}/includes)

add_executable(CameraCaptureServer
  main.cpp
  includes/cameracapture.h src/cameracapture.cpp
  includes/cameracontroller.h src/cameracontroller.cpp
  includes/capturesender.h src/capturesender.cpp
  ../GeneralIncludes/controlstructs.h
  ../GeneralIncludes/constants.h
)

target_link_libraries(CameraCaptureServer
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    ${OpenCV_LIBS}
)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    target_link_libraries(CameraCaptureServer
        /usr/lib/libwiringPi.so
    )
endif()

include(GNUInstallDirs)
install(TARGETS CameraCaptureServer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
