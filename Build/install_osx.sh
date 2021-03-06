#!/usr/bin/env bash

# Compiling Traycer

cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
make all

# Moving libraries

chmod u+x run.sh
cp run.sh Application/.

# Cleaning deployement files

rm Makefile
rm Application/Makefile
rm *.cmake
rm Application/*.cmake
rm -rf CMakeFiles
rm -rf Application/CMakeFiles
rm CMake*