#!/bin/bash
g++ -Wall -std=c++14 -fPIC $(pkg-config --cflags Qt5Widgets) main.cpp *.cc $(pkg-config --libs Qt5Widgets) -o main.out
./main.out
