from collections import Counter
from fractions import gcd

n = int(input())
xys = [tuple(map(int, input().split())) for _ in range(n)]
MOD = 998244353

excludes = 0
for i, (x1, y1) in enumerate(xys):
    slopes = []
    for x2, y2 in xys[i + 1:]:
        dx, dy = x2 - x1, y2 - y1
        if dx == 0:
            slopes.append(1j)
        elif dy == 0:
            slopes.append(1)
        else:
            m = gcd(dx, dy)
            slopes.append(dx // m + dy // m * 1j)
    for c in Counter(slopes).values():
        if c > 1:
            excludes += 2 ** c - c - 1
    excludes %= MOD

print((pow(2, n, MOD) - excludes - (n * (n - 1) // 2) - n - 1) % MOD)