#! /bin/bash
set -euC

g++ -std=gnu++20 main.cpp -o main
oj t -c ./main