#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    moods = fin.readline().strip()

    points = 0
    seq = []
    last = None
    for c in moods:
        if not seq or seq[-1] != c:
            seq.append(c)
        else:
            seq.pop()
            points += 10
    points += len(seq) // 2 * 5
    print("Case #%d: %s" % (case, points))

