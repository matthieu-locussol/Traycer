#!/bin/sh

echo "Running Traycer.."
echo ""

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"$PWD/Submodules"

chmod +x Binaries/Traycer

./Binaries/Traycer