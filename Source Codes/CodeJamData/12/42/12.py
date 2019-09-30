#!/usr/bin/python3

import sys
import heapq

def case():
    N,W,L = [int(x) for x in sys.stdin.readline().split()]
    r = [int(x) for x in sys.stdin.readline().split()]
    rs = sorted([[r[i],i] for i in range(0,N)], reverse=True)
    a = [0 for x in range(0, N)]
    x = 0
    y = 0
    ny = 0
    for ss in rs:
        s = ss[0]
        if x + 2*s > W:
            y = ny
            x = 0
        sx = 0 if x == 0 else x + s
        sy = 0 if y == 0 else y + s
        a[ss[1]] = [sx, sy]
        if x == 0:
            ny += 2*s
        x = sx + s
    ans = ""
    for aa in a:
        ans += " %s %s" % (aa[0],aa[1])
    return ans

T = int(sys.stdin.readline())
for i in range(1,T+1):
    r = case()
    print("Case #%s:%s" % (i, r))
    

