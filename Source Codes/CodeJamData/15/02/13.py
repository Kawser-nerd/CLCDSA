#!/usr/bin/env python3


T = int(input())
for case in range(1, T+1):
    input()
    p = [int(i) for i in input().split()]
    ans = min(e+sum(-(-i//e)-1 for i in p) for e in range(1, max(p)+1))
    print("Case #{}: {}".format(case, ans))

