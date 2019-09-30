#!/usr/bin/env python3

import sys

def solve ( tt ):
    n = int (input ())
    data = []
    for i in range (n):
       data.append (input ().split ())
    S = 0
    T = 1
    g = [[], []]
    m = {}

    def edge ( u, v, c ):
        # print ("edge: %d -> %d (%d)" % (u, v, c), file=sys.stderr)
        g[u].append ([v, 0, c, len (g[v])])
        g[v].append ([u, 0, 0, len (g[u]) - 1])
    def word ( w ):
        nonlocal g, m
        if w in m:
            return
        m[w] = len (g)
        g.append ([])
        g.append ([])
        edge (m[w], m[w] + 1, 1)
    for w in data[0]:
        word (w)
        edge (S, m[w], 1000000)
    for w in data[1]:
        word (w)
        edge (m[w] + 1, T, 1000000)
    for s in data[2:]:
        x = len (g)
        g.append ([])
        for w in s:
            word (w)
            edge (m[w] + 1, x, 1000000)
            edge (x, m[w], 1000000)
    c = [0 for x in g]
    def dfs ( u, it ):
        nonlocal g, c, T
        if u == T:
            return True
        c[u] = it
        for i, edge in enumerate (g[u]):
            t, f, cap, r = edge
            if c[t] == it or f >= cap:
                continue
            if not dfs (t, it):
                continue
            g[u][i][1] += 1
            g[t][r][1] -= 1
            return True
        return False

    ans = 0
    it = 1
    while dfs (S, it):
        ans += 1
        it += 1
    print ("Case #%d: %d" % (tt, ans))
    # ans = len (m) - ans
    # print ("Case #%d: %d" % (tt, ans))
    

tn = int (input ())
for tt in range (tn):
    solve (tt + 1)

