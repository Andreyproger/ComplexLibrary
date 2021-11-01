#!/bin/sh

BUILD_DIR="build"
APPLICATION_NAME="Compllib"

test -d "$BUILD_DIR" && rm -Rf $BUILD_DIR

clear
mkdir -p $BUILD_DIR
cd $BUILD_DIR
cmake ..
make -j3
echo "\n\n"

test -f "$APPLICATION_NAME" && ./$APPLICATION_NAME
