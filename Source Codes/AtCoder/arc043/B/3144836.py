from bisect import bisect_left as bl, bisect_right as br
from itertools import accumulate

N = int(input())
D = sorted([int(input()) for i in range(N)])
mod = 10 ** 9 + 7

R = []
for c in D:
    R.append(N - bl(D, 2 * c))
R = list(accumulate(R[::-1]))[::-1]

ans = 0
for b in D:
    ans += br(D, b / 2) * R[min(N - 1, bl(D, 2 * b))] % mod
print(ans % mod)