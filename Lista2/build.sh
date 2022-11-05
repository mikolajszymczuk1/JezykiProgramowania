#!/bin/bash
# Run this script to build program A and program B

# Clear out dir before

echo "Clear out dir ..."

oFiles=out/*.o
mainPath=out/main

if [ -f "$oFile" ]; then
    rm "$oFiles"
fi

if [ -f "$mainPath" ]; then
    rm "$mainPath"
fi

echo "Done !"

# Compile all important elements

echo "Start compiling important modules ..."

g++ -c classes/Point2D/Point2D.cpp -o out/Point2D.o
g++ -c classes/Point3D/Point3D.cpp -o out/Point3D.o
g++ -c classes/Vector3D/Vector3D.cpp -o out/Vector3D.o

echo "Done !"

# Compile main programs

echo "Start compiling main programs ..."

g++ -c main.cpp -o out/main.o

echo "Done !"

# Prepare complated programs

echo "Building final programs ..."

g++ out/Point2D.o out/Point3D.o out/Vector3D.o out/main.o -o out/main

echo "Done !"
echo "Build complete !"
