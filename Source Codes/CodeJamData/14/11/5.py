#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p1.out", "w")

T = int(fin.readline())

def conv (s):
    return int(s, 2)

for i in range(T):
    N, L = map(int, fin.readline().split())
    ans = L+1
    device = sorted(map(conv, fin.readline().split()))
    outlet = map(conv, fin.readline().split())
    for j in range(len(outlet)): #try mapping device[0] to outlet[j]
        bits = device[0] ^ outlet[j]
        def flip(t):
            return t ^ bits
        new_out = sorted(map(flip, outlet))
        if new_out == device:
            ans = min(ans, bin(bits).count("1"))
        
    fout.write("Case #" + str(i+1) + ": ")
    if ans == L+1:
        fout.write("NOT POSSIBLE\n")
    else:
        fout.write(str(ans) + "\n")
