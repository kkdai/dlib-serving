#!/bin/bash
set -e
rm -rf CMakeCache.txt CMakeFiles Makefile
# rm -rf build
mkdir -p build
# export VERBOSE=1
(cd build && cmake \
    -DDLIB_ROOT=dlib \
    -DDLIB_PNG_SUPPORT=yes \
    -DDLIB_JPEG_SUPPORT=yes \
    -DDLIB_GIF_SUPPORT=yes \
    -DUSE_AVX_INSTRUCTIONS=yes \
    -DUSE_SSE4_INSTRUCTIONS=yes \
    .. && cmake --build . -- -j)
