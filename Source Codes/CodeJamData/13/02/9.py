#!/usr/bin/env python

def solve(lawn):
    n = len(lawn)
    m = len(lawn[0])
    rowmax = [max(lawn[r]) for r in range(n)]
    colmax = [max(lawn[r][c] for r in range(n)) for c in range(m)]
    for r in range(n):
        for c in range(m):
            h = lawn[r][c]
            if h != rowmax[r] and h != colmax[c]:
                return False
    return True

cases_count = int(raw_input())
for t in range(cases_count):
    lawn = []
    n, m = [int(i) for i in raw_input().split(' ')]
    for _ in range(n):
        lawn.append([int(i) for i in raw_input().split(' ')])
    print "Case #%d: %s" % (t+1, "YES" if solve(lawn) else "NO")
