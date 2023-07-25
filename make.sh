#!/bin/bash

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make

rm /home/Siaospeed/mcl/so/libStatus.so
mv ./libStatus.so /home/Siaospeed/mcl/so/libStatus.so
