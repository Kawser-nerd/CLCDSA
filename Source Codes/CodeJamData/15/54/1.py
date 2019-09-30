#!/usr/bin/env python3

from collections import Counter

T = int(input())
for case in range(1, T+1):
    P, = [int(i) for i in input().split()]
    E = [int(i) for i in input().split()]
    F = [int(i) for i in input().split()]
    neg = min(E)
    E = [i-neg for i in E]
    c = Counter(dict(zip(E, F)))
    ans = []
    while c[0] > 1:
        ans.append(0)
        d = Counter()
        for k in c:
            d[k] = c[k]//2
        c = d
    del c[0]
    while c:
        e = min(c)
        ans.append(e)
        c[e] -= 1
        d = Counter()
        for k in sorted(c.keys()):
            if c[k] > 0:
                d[k] = c[k]
                assert k+e in c
                c[k+e] -= c[k]
        c = d
    while neg:
        t = max(i for i in ans if i <= -neg)
        del ans[ans.index(t)]
        ans.append(-t)
        neg += t
    ans.sort()
    ans = ' '.join(map(str, ans))
    print("Case #{}: {}".format(case, ans))

