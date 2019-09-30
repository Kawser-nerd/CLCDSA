# -*- coding: utf-8 -*-
from math import ceil

left = -1
right = 0

n,a,b = map(int, input().split())
h = []
for _ in range(n):
    h.append(int(input()))
    right += h[-1]//b+1

def check(t):
    cnt = 0
    for i in range(n):
        if h[i]-b*t>0:
            cnt += ceil((h[i]-b*t)/(a-b))
    return cnt<=t

while left+1<right:
    mid = (left+right)//2

    if check(mid):
        right = mid
    else:
        left = mid


print(right)