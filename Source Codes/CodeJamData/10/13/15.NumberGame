#!/usr/bin/python

from __future__ import print_function
from __future__ import division

import sys

def winner(A, B, arya=True):
    if A==B:
        return not arya
    big = max(A,B)
    small = min(A,B)
    if not big % small:
        return arya
    maxK = big // small
    for k in xrange(maxK, 0, -1):
        if winner(big-k*small, small, not arya) == arya:
            return arya
    else:
        return not arya


def main(filename):
    with open(filename, "r") as f:
        for case, line in enumerate(f):
            if not case:
                T = int(line.strip())
                continue
            if case > T:
                break
            A1, A2, B1, B2 = (int(c) for c in line.split())
            count = 0
            for a in xrange(A1,A2+1):
                for b in xrange(B1,B2+1):
                    count += winner(a,b)
            print("Case #{0}: {1}".format(case, count))

if __name__ == "__main__":
    main(sys.argv[1])
    sys.exit(0)

