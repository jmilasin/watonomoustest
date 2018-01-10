#!/bin/bash

make -f Makefile || exit
sleep 1
cpplint wato.cpp
sleep 1
./wato.out