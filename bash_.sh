#!/bin/bash

files="simple_iteration.cpp"
exe=simple
if [ -e $exe ]
then
    rm $exe
fi
for fl in $files
do
g++ -c $fl
done
obj=$(find -name '*.o')
g++ $obj -o $exe
./$exe

