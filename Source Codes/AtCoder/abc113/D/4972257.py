import itertools

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
counts = [[0 for _ in range(width)] for _ in range(width)]
for pattern in patterns:
    for w in range(width):
        if w in pattern:
            counts[w][w + 1] += 1
        elif w - 1 in pattern:
            counts[w][w - 1] += 1
        else:
            counts[w][w] += 1

# 0 ???? h ? w ?????????
# dp[h][w]
dp = [[0 for _ in range(width)] for _ in range(height)]
dp[0] = counts[0].copy()
for h in range(height - 1):
    for w in range(width):
        # w ?????????
        dp[h + 1][w] = sum([dp[h][v] * counts[v][w] for v in range(width)]) % MOD

if width == 1:
    print(1)
else:
    print(dp[-1][k])