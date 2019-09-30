#!/usr/bin/env python

import sys

readline = lambda : sys.stdin.readline()

N = int(readline())

def solve(tree, start, V):
#     d = 0
#     a = 1
#     for t in range(1, len(tree)):
#         print tree[t],
#         if t - d == a:
#             print
#             a *= 2
#             d = t
#     print
#     print

    for t in range(start+1, len(tree)):
        if tree[t][0]:
            tree[t] = 10001, 0
        else:
            tree[t] = 0, 10001

    for t in range(start, 0, -1):
        G, C = tree[t]
        a0, a1 = tree[t*2]
        b0, b1 = tree[t*2+1]

        and0 = min(a0 + b0, min(a0 + b1, a1 + b0))
        and1 = a1 + b1
        or0 = a0 + b0
        or1 = min(a1 + b0, min(a1 + b1, a0 + b1))

        if C:
            if G:
                c0 = min(and0, or0 + 1)
                c1 = min(and1, or1 + 1)
            else:
                c0 = min(and0 + 1, or0)
                c1 = min(and1 + 1, or1)
        else:
            if G:
                c0 = and0
                c1 = and1
            else:
                c0 = or0
                c1 = or1
        tree[t] = c0, c1
        
#     d = 0
#     a = 1
#     for t in range(1, len(tree)):
#         print tree[t],
#         if t - d == a:
#             print
#             a *= 2
#             d = t
#     print
#     print

    t = tree[1][V]
    if t > 10000:
        return "IMPOSSIBLE"
    else:
        return str(t)
    
for n in range(N):
    M, V = map(int, readline().split())
    
    tree = [0]
    for m in range(M):
        x = map(int, readline().split())
        tree.append(x)

    print "Case #%d: %s" % (n+1, solve(tree, (M-1)/2, V))
