#!/bin/bash
echo "Start the building process..."

if cmake -B build; then
    echo "CMake configuration successful"
else
    echo "CMake configuration failed"
    exit 1
fi

if cmake --build build; then
    echo "Build successful! Run with: ./build/bin/shell"
else
    echo "Build failed"
    exit 1
fi
