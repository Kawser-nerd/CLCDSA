n = int(input())

dp = [1 for i in range(0,n+1)]
c = list()
c.append(-1)
d = {}
for i in range(1,n+1):
    c.append(int(input()))

for i in range(1,n+1):
    if c[i] in d:
        j = d[c[i]]
        d[c[i]] = i
        if c[i-1] != c[i]:
            dp[i] = dp[i-1]+dp[j]
            continue
    else:
        d[c[i]] = i
    dp[i] = dp[i-1]
print(dp[-1]%(10**9+7))