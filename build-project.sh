#!/bin/bash

OUTPUT_DIR="build"

function check_execution() {
    if [[ $1 -ne 0 ]]; then
        echo "[MSH] - Built failed."
        exit 1
    fi
}

function generate_output_dir() {
    if [[ ! -d $OUTPUT_DIR ]]; then
        mkdir build
    else
        local all_deletable_files="$OUTPUT_DIR/*"
        rm -r $all_deletable_files
    fi 
}

function generate_makefiles() {
    cd $OUTPUT_DIR
    cmake -G "Unix Makefiles" ..
    make all
}

if [ "$1" == "-h" ]; then
    echo $'-- Marshmallow Simulator project builder --
When executed successfully it will create an executable file.
Requirements:
\t- A C++ compiler
\t- CMake
\t- Make\n'
    echo "Usage: `basename $0` [-h]"
  exit 0
fi

echo "[MSH] - Building Marshmallow Simulator. Please wait."

generate_output_dir
check_execution $1

generate_makefiles
check_execution $1

echo "[MSH] - Done. Check console for details. Makefile in '$OUTPUT_DIR'."
