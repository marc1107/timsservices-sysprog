#!/bin/sh

command1="gcc -W -Wall -std=c11 -pedantic -c -I . liste.c fachnote.c"

echo $command1
eval $command1
if [ $? -ne 0 ]; then
    echo "build failed"
    exit 1
fi 


lib_command="ar rs libaufgabe5.a fachnote.o liste.o"
echo $lib_command
eval $lib_command
if [ $? -ne 0 ]; then
    echo "build failed"
    exit 1
fi