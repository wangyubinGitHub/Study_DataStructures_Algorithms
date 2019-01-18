cmake_minimum_required(VERSION 3.4)
include_directories(staitstics)
aux_source_directory(./staitstics DIR_STATISTICS_SRCS)
add_library(statistics ${DIR_STATISTICS_SRCS})
