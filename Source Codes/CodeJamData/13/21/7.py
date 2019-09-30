#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys
fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    A, N = map(int, fin.readline().split())
    motes = list(map(int, fin.readline().split()))
    limit = len(motes)
    limit1 = limit + 1
    motes.sort()

    last = [0] * limit1
    last[0] = A
    for mote in motes:
        current = [0] * limit1
        for used, size in enumerate(last):
            newsize = size
            for moves in range(used, limit1):
                if newsize > mote:
                    current[moves] = max(current[moves], newsize + mote)
                newsize = newsize*2 - 1
            if used < limit:
                current[used+1] = max(current[used+1], size)
        last = current

    best = None
    for used, size in enumerate(last):
        if size > 0:
            best = used
            break

    print("Case #%d: %s" % (case, best))

