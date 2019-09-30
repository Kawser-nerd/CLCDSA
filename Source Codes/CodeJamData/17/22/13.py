#!/usr/bin/env python

no = 'IMPOSSIBLE'

ch = 'ROYGBV'

mat = [ [0, 0, 1, 1, 1, 0],
        [0, 0, 0, 0, 1, 0],
        [1, 0, 0, 0, 1, 1],
        [1, 0, 0, 0, 0, 0],
        [1, 1, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0]]

cycle = lambda x : x % 6
others = lambda x : map(cycle, range(x + 1, x + 6))

def sol():
    c = list(map(int, input().split()[1:]))
    n = sum(c)
    if max(c) * 2 > n:
        return no
    if max(c) * 2 == n:
        k = c.index(max(c))
        s = ''
        for i in others(k):
            if not c[i] or mat[i][k]:
                s += (ch[i]+ch[k])* c[i]
            else:
                return no
        return s
    for k in [1, 3, 5]:
        if c[k] and c[k] >= c[cycle(k + 3)]:
            return no
    d = [c[0] - c[3], c[2] - c[5], c[4] - c[1]]
    if max(d) * 2 > sum(d):
        return no
    x, y, z = 0, 1, 2
    if d[x] < d[y]: x, y = y, x
    if d[x] < d[z]: x, z = z, x
    w = d[y] + d[z] - d[x]
    s = w * (ch[x * 2] + ch[y * 2] + ch[z * 2]) +  (d[y] - w) * (ch[x * 2] + ch[y * 2]) + (d[z] - w) * (ch[x * 2] + ch[z * 2])
    for k, p in zip([1, 3, 5], [4, 0, 2]):
        if c[k]:
            i = s.find(ch[p])
            s = s[:i] + c[k] *(ch[p] + ch[k]) + s[i:]
    return s

for ti in range(int(input())):
    print("Case #%d: %s" % (ti + 1, sol()))
