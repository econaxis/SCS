cmake_minimum_required (VERSION 2.6)
project (CF)

add_compile_definitions(DEBUG)
add_compile_options(--std=c++14 -Wall -O2)
include_directories(include)
set (CPP  src/main.cpp src/LCS_Scorer.cpp src/noerror.cpp)
set (HEADERS include/LCS_Scorer.h include/noerror.h)
add_executable(SCS  ${CPP} ${HEADERS})

add_executable(TGEN src/testgen.cpp)
