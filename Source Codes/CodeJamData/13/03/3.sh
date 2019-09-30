#!/bin/bash

echo 'Generating fair squares...' >&2
./c_gen | sort -n | sed 's/$/^2/' | gp -f -q > c_nums.txt

echo 'Solving the problem...' >&2
./c_solve
