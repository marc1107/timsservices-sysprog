#!/bin/sh

command1="gcc -W -Wall -std=c11 -pedantic -c -I . liste.c fachnote.c"

echo $command1
eval $command1
if [ $? -ne 0 ]; then
    echo "build failed"
    exit 1
fi 


command2="gcc -shared fachnote.o liste.o -o libaufgabe5.so"

echo $command2
eval $command2
if [ $? -ne 0 ]; then
    echo "build failed"
    exit 1
fi 