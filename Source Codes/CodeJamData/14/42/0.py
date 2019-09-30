#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p2.out", "w")

T = int(fin.readline())
for i in xrange(T):
    N = int(fin.readline())
    A = map(int, fin.readline().split())

    ans = 0
    for j in xrange(len(A)):
        l = 0
        r = 0
        for k in xrange(len(A)):
            if A[k] > A[j]:
                if k < j:
                    l += 1
                else:
                    r += 1
        ans += min(l, r)

    fout.write("Case #" + str(i+1) + ": " + str(ans) + "\n")
