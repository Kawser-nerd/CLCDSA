#!/usr/bin/python3

import sys
import heapq

def case():
    N = int(sys.stdin.readline())
    vines = []
    for i in range(0,N):
        vines.append([int(x) for x in sys.stdin.readline().split()])
    D = int(sys.stdin.readline())
    vines.append([D,0])
    reach = [-1 for i in range(0,N+1)]
    reach[0] = vines[0][0]
    for i in range(0,N+1):
        for j in range(i+1,N+1):
            if vines[j][0] > vines[i][0] + reach[i]:
                break
            r = min(vines[j][1], vines[j][0]-vines[i][0])
            if r > reach[j]:
                reach[j] = r
    if reach[N] != -1:
        return "YES"
    return "NO"
        

T = int(sys.stdin.readline())
for i in range(1,T+1):
    r = case()
    print("Case #%s: %s" % (i, r))
    

