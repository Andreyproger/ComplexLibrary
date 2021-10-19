#!/bin/sh

BUILD_DIR="build"
APPLICATION_NAME="Compllib"

if [ -d "$BUILD_DIR" ]; then
  rm -Rf $BUILD_DIR
fi

mkdir -p $BUILD_DIR
cd $BUILD_DIR
cmake ..
make -j3
echo ""
echo ""
./$APPLICATION_NAME