#!/bin/bash

g++ vulnerable.cpp
./a.out < test/t1.txt > test/o1.txt
./a.out < test/t2.txt > test/o2.txt
./a.out < test/t3.txt > test/o3.txt