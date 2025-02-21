#!/bin/bash

if [ "$1" == "clean" ]; then
    echo "Cleaning build artifacts..."
    make clean
    exit 0
fi

if [ "$1" == "test" ]; then
    echo "Running tests..."
    # Add your test command here (e.g., ./run_tests)
    exit 0
fi

# Build the project (if needed)
echo "Building the project..."
make

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful! Running the program..."
    ./hello_world
else
    echo "Build failed. Please check the errors above."
    exit 1
fi
