# -*- coding: utf-8 -*-

n,x = map(int,input().split())
a = list(map(int,input().split()))

ans = 0
for i in range(n-1):
    diff = max(0,(a[i+1] + a[i]) - x)
    ans += diff
    if a[i+1] >= diff:
        a[i+1] = a[i+1] - diff
    else:
        a[i] -= diff - a[i+1]
        a[i+1] = 0

print(ans)