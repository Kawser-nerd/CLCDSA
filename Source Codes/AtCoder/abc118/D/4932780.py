N, M = list(map(int, input().split()))
A = list(map(int, input().split()))
A.sort(reverse=True)

V = [-1, 2, 5, 5, 4, 5, 6, 3, 7, 6]

dp = [-1e10] * (N + 1)
dp[0] = 0

for i in range(1, N + 1):
    # i ??????????? dp ????
    l = [dp[i - V[j]] + 1 for j in A if i - V[j] >= 0]
    if l:
        dp[i] = max(l)
# ????????????
n = N
while n > 0:
    for j in A:
        if n - V[j] < 0: continue
        if dp[n] == dp[n - V[j]] + 1:
            print(j, end='')
            n = n - V[j]
            break
print()