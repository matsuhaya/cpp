#! /bin/bash
set -euC

g++-12 -std=gnu++20 main.cpp -o main
oj t -c ./main