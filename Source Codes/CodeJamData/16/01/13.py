#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p1.out", "w")

def find_digs(N):
    l = []
    while N > 0:
        l.append(N % 10)
        N /= 10
    return l

T = int(fin.readline())
for tt in xrange(T):
    N = int(fin.readline())
    ans = 0
    if N == 0:
        ans = "INSOMNIA"
    else:
        digs = set(find_digs(N))
        i = 1
        while len(digs) != 10:
            i += 1
            digs |= set(find_digs(i * N))
        ans = i * N

    fout.write("Case #" + str(tt+1) + ": " + str(ans) + "\n")
