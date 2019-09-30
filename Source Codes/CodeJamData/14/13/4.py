#! /usr/bin/env python

import sys
import random
fin = open(sys.argv[1], "r")
fout = open("p3.out", "w")

T = int(fin.readline())
for i in range(T):
    N = int(fin.readline())
    perm = map(int, fin.readline().split())
    good = 0
    bad = 0
    for j in range(N):
        if perm[j] > j+1:
            bad += 1
        elif perm[j] <= j+1:
            good += 1

    print bad, good    

    if bad >= good + 20:
        fout.write("Case #" + str(i+1) + ": BAD\n")
    else:
        fout.write("Case #" + str(i+1) + ": GOOD\n")
