from bisect import bisect_left as bl, bisect_right as br
from itertools import accumulate as ac

n = int(input())
D = sorted([int(input()) for i in range(n)])
m = 10 ** 9 + 7

R = [n - bl(D, 2 * i) for i in D]

R = list(ac(R[::-1]))[::-1]

f=lambda y,x:(y + br(D, x / 2) * R[min(n - 1, bl(D, 2 * x))] )% m
a = list(ac(D,f))
print(a[-1]-a[0])