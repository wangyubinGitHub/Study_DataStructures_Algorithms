cmake_minimum_required(VERSION 3.4)
aux_source_directory(. DIR_MUSIC_THEORY_SRCS)
add_library(musicTheory ${DIR_MUSIC_THEORY_SRCS})
