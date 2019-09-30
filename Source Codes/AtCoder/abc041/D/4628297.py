n, m = map(int, input().split())
xy = [tuple(int(x) - 1 for x in input().split()) for _ in range(m)]

R = [[] for _ in range(n)]

for x, y in xy:
    R[x].append(y)

dp = [0 for _ in range(2 ** n)]
dp[0] = 1
for i in range(1, 2 ** n):
    b = list(str(bin(i)))[2:]
    s = ['0'] * (n-len(b)) + b
    for j in range(n):
        if s[j] == '1':
            for x in R[j]:
                if s[x] == '1':
                    break
            else:
                dp[i] += dp[i - (2 ** (n-1-j))]

print(dp[2**n-1])