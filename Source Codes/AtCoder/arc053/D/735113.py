def ints():
    return list(map(lambda s: int(s) - 1, input().split()))
m = 10**9 + 7
n = int(input())
A = ints()
B = ints()
Ainv = [0 for i in range(n)]
Binv = [0 for i in range(n)]
for i in range(n):
    Ainv[A[i]] = i
    Binv[B[i]] = i

v2nanameIndex = [0 for i in range(n)]
for v in range(n):
    v2nanameIndex[v] = Ainv[v] - Binv[v] + (n-1)

dp = [[0 for i in range(n)] for j in range(n)]
nanameDp = [[0] for i in range(2 * n - 1)]

for i in range(n):
    for j in range(n):
        if i == 0 or j == 0:
            dp[i][j] = 1
        else:
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % m
        if A[i] == B[j]:
            v = A[i]
            nanaI = v2nanameIndex[v]
            naDp = nanameDp[nanaI]
            dp[i][j] = (dp[i][j] - (naDp[-1])  + m) % m
            naDp.append(dp[i][j])
            for k in range(1,len(naDp)):
                naDp[k] = (naDp[k] + naDp[k - 1]) % m
print(dp[-1][-1])