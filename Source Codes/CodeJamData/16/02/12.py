#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p2.out", "w")

T = int(fin.readline())
for tt in xrange(T):
    s = list(fin.readline().strip())
    s = map(lambda x: x == '+', s)
    s.append(True)
    ans = 0
    for i in xrange(len(s) - 1):
        if s[i] != s[i+1]:
            ans += 1
    fout.write("Case #" + str(tt+1) + ": " + str(ans) + "\n")
