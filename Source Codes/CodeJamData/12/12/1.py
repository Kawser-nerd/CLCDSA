#!/usr/bin/env python3

import sys

t_n = int(sys.stdin.readline())

for t_t in range(1, t_n+1):
    n = int(sys.stdin.readline())
    a = []
    for i in range(n):
      a.append(list(map(int, sys.stdin.readline().split())))
    a = list(sorted(a, key = lambda x: (x[1], x[0])))
    b = [0 for x in range(n)]
    ans = 0
    stars = 0
    bad = False
    for i in range(n):
        j = n - 1
        while stars < a[i][1] and j >= i:
            if b[j] == 0 and a[j][0] <= stars:
                stars += 1
                ans += 1
                b[j] = 1
                j = n
            j -= 1
        if a[i][1] > stars:
            bad = True
        ans += 1
        stars += 2 - b[i]
    if bad:
        print("Case #%d: Too Bad" % t_t)
    else:
        print("Case #%d: %d" % (t_t, ans))

