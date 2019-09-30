#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    N, L = (int(i) for i in input().split())
    a = sorted(int(i, 2) for i in input().split())
    b = sorted(int(i, 2) for i in input().split())
    ans = L+1
    for i in b:
        if sorted(a[0] ^ i ^ j for j in a) == b:
            ans = min(ans, bin(a[0] ^ i).count('1'))
    if ans == L+1:
        ans = 'NOT POSSIBLE'
    print("Case #{}: {}".format(case, ans))

