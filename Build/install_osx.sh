#!/usr/bin/env bash

# Compiling SFML from sources

cd Submodules/SFML
git checkout 2.5.x
cd ../..

mkdir -p Submodules/SFML/Build
cd Submodules/SFML/Build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
make -j2
sudo make install

cd ../../..

# Compiling TGUI from sources

cd Submodules/TGUI
git checkout 0.8
git apply ../../Build/Patches/comment-string-tgui.patch
cd ../..

mkdir -p Submodules/TGUI/Build
cd Submodules/TGUI/Build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
make tgui -j2
sudo make install/fast

cd ../../..

# Compiling Traycer

cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
make all

# Moving libraries

mkdir -p Application/Submodules/
cp ../Submodules/SFML/Build/lib/* Application/Submodules/.
cp ../Submodules/TGUI/Build/lib/* Application/Submodules/.
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