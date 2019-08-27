#!/bin/bash

INCLUDE_DIR='./include'
MODULES='./lib'


#compile + build source
gcc -c main.c -I $INCLUDE_DIR $MODULES/*.c
mkdir build
mv *.o build

#link sources
gcc -I $INCLUDE_DIR build/*.o -pg -o test.out

