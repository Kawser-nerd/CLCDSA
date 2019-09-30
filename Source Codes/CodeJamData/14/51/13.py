#!/usr/bin/python3

import sys

t = int(sys.stdin.readline())

def solve(n, p, q, r, s):
    l = [(i * p + q) % r + s for i in range(n)]
    vsota = sum(l)
    cum = [0]
    for x in l:
        cum.append(cum[-1] + x)
    best = 0.0
    
    for b in range(n-1, -1, -1):
        # Last part is l[b:]
        # Search for a
        # s = [cum[a], cum[b] - cum[a], cum[n] - cum[b]]
        rem = vsota - (cum[n] - cum[b])
        al = 0
        ar = b
        # Binary search for a
        while al + 1 < ar:
            amid = (al + ar) // 2
            left = cum[amid]
            right = cum[b] - cum[amid]
            if left > right:
                ar = amid
            else:
                al = amid
        s = [cum[al], cum[b] - cum[al], cum[n] - cum[b]]
        s.sort()
        p = (s[0] + s[1]) / vsota
        best = max(best, p)
        s = [cum[ar], cum[b] - cum[ar], cum[n] - cum[b]]
        s.sort()
        p = (s[0] + s[1]) / vsota
        best = max(best, p)
    return best

for test_case in range(1, t+1):
    n, p, q, r, s = map(int, sys.stdin.readline().strip().split())
    print("Case #{0}: {1}".format(test_case, solve(n, p, q, r, s)))