import collections

n, m = map(int, input().split())
pres = collections.defaultdict(list)
for _ in range(m):
    x, y = map(lambda s : int(s) - 1, input().split())
    pres[y].append(x)

dp = [0] * (2 ** n)
dp[0] = 1
for bit in range(2 ** n - 1):
    for i in range(n):
        if (bit & (1 << i)) == 0 and all((bit & (1 << j)) != 0 for j in pres[i]):
            dp[bit | (1 << i)] += dp[bit]

print(dp[2 ** n - 1])