cmake_minimum_required(VERSION 3.4)
aux_source_directory(. DIR_UTILS_SRCS)
add_library(utils ${DIR_UTILS_SRCS})
