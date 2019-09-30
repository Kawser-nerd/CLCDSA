from bisect import bisect_left, bisect_right
from itertools import accumulate

N = int(input())
D = sorted([int(input()) for i in range(N)])
mod = 10 ** 9 + 7

R = []
for i in range(N):
    R.append(N - bisect_left(D, D[i]*2))
R = list(accumulate(R[::-1]))[::-1]

ans = 0
for b in D:
    ans += bisect_right(D, b / 2) * R[min(N-1, bisect_left(D, b*2))] % mod

print(ans % mod)