import itertools

import numpy as np

height, width, k = map(int, input().split())
k -= 1

MOD = 1000000007

# 1 ??????? valid ?????????
patterns = []
for r in range(width - 1):
    for pattern in itertools.combinations(range(width - 1), r):
        # ?????????
        if all(abs(a - b) != 1 for a, b in zip(pattern[:-1], pattern[1:])):
            patterns.append(pattern)

# counts[w][v]: 1 ?? w ?? v ??????????
counts = np.zeros((width, width))
for pattern in patterns:
    for w in range(width):
        if w in pattern:
            counts[w][w + 1] += 1
        elif w - 1 in pattern:
            counts[w][w - 1] += 1
        else:
            counts[w][w] += 1
if width == 1:
    counts[0][0] = 1

# 0 ???? h ? w ?????????
# dp[h][w]
dp = np.zeros((height, width))
dp[0] = counts[0].copy()
for h in range(height - 1):
    dp[h + 1] = np.dot(dp[h], counts) % MOD

print(int(dp[-1][k]))