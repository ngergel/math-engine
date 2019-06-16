#!/bin/bash
# Format script for the entire project.
# Run this script to automatically format every header & cpp file.
# Usage: ./format.sh

FILES="$(find . -type f -name "*.h" -o -name "*.cpp")"
clang-format -i $FILES
