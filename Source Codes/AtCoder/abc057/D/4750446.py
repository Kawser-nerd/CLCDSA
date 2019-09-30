import numpy as np
from bisect import bisect_left
n, a, b = map(int, input().split())
v = sorted(map(int, input().split()))[::-1]
print(sum(v[:a])/a)
prev = v[0]
cnt = 0
rle = []
for i in v:
    if i != prev:
        rle.append(cnt)
        prev = i
        cnt = 1
    else:
        cnt += 1
rle.append(cnt)
cum = [0]
for i in rle:
    cum.append(cum[-1] + i)

left = bisect_left(cum, a)
m = rle[left-1]
a = a - cum[left-1]
if left == 1:
    b = min(cum[left], b) - cum[left-1]
else:
    b = a

from math import factorial
def comb(n, r):
    return factorial(n) // factorial(n-r) // factorial(r)

ans = 0
for i in range(a, b+1):
    ans += comb(m,i)
print(ans)