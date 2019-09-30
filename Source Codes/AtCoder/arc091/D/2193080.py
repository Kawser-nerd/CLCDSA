import sys

sys.setrecursionlimit(10000000)
from math import ceil


def grundy(a, k):
    if a < k:
        return 0
    d, m = divmod(a, k)
    if m == 0:
        return d
    d1 = d + 1
    if d > k:
        return grundy(a - d1, k)
    e = ceil(m / d1) * d1
    return grundy(a - e, k)


n = int(input())
nim = 0
for _ in range(n):
    a, k = map(int, input().split())
    nim ^= grundy(a, k)
print('Takahashi' if nim > 0 else 'Aoki')