cmake_minimum_required(VERSION 3.4)
project(ap)

#define
add_definitions(-std=c++11)

# Add header file include directories
include_directories(./staitstics/staitstics 
    ./musicTheory 
    ./utils 
    ./test
    /usr/local/include
    )#添加多目录的路径
# Add link directories
link_directories(/usr/local/lib)

# Add block directories
add_subdirectory(staitstics)
add_subdirectory(musicTheory)
add_subdirectory(utils)
add_subdirectory(test)
# Target
add_executable(ap main.cpp)
target_link_libraries(
    ap
    statistics 
    musicTheory 
    utils 
    test
    boost_filesystem
    boost_system)
