B = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]
N, M = map(int, input().split())
A = list(map(int, input().split()))
dic = {i: B[i] for i in A}
dp = [0] * (N + 1)
for i in range(N + 1):
    for j in A:
        if i>0 and dp[i]==0:
            break
        if i + dic[j] <= N:
            dp[i + dic[j]] = max(dp[i] * 10 + j, dp[i + dic[j]])
print(dp[N])