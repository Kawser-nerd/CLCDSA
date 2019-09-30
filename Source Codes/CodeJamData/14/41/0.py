#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p1.out", "w")

T = int(fin.readline())
for i in xrange(T):
    N, X = map(int, fin.readline().split())
    S = sorted(map(int, fin.readline().split()))

    cur = 0
    for j in reversed(xrange(len(S))):
        if j <= cur:
            break
        elif S[cur] + S[j] <= X:
            cur += 1
        
    fout.write("Case #" + str(i+1) + ": " + str(N-cur) + "\n")
                

