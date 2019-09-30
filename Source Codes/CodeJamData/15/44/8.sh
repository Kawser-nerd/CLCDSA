#!/bin/bash

g++ solve.cpp -O2

for n in 2 3 4 5 6
do
    for m in 3 4 5 6
    do
        ./a.out $n $m 2> lol 
        echo -ne "($n, $m): " >> all
        python uniq.py < lol >> all
        echo $n $m
    done
done
