#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <main_file>"
    exit 1
fi

main_file="$1"
output_file="${main_file%.*}"

g++ "$main_file" -o "$output_file"

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    ./"$output_file"
else
    echo "Compilation failed."
fi
