#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    input()
    m = [int(i) for i in input().split()]
    diff = [i-j for i, j in zip(m[:-1], m[1:])]
    ans1 = sum(i for i in diff if i>0)
    rate = max(diff)
    ans2 = sum(min(i, rate) for i in m[:-1])
    print("Case #{}: {} {}".format(case, ans1, ans2))

