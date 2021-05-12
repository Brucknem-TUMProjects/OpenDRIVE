cmake_minimum_required(VERSION 3.17)

find_package(XercesC REQUIRED)

add_library(OpenDRIVEStandard
        standard/OpenDRIVE_1.4H_Schema_Files.cxx
        )

configure_file(standard/OpenDRIVE_1.4H_Schema_Files.xsd COPYONLY)

target_include_directories(OpenDRIVEStandard
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
        )
target_link_libraries(OpenDRIVEStandard XercesC::XercesC)

add_subdirectory(googletest)
add_subdirectory(yaml-cpp)