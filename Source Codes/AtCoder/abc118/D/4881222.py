N, M = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort(reverse=1)
num = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]

dp = [0] * (N+1)

for i in range(1, N+1):
    now = - 10 ** 9
    for aa in a:
        if i - num[aa] >= 0:
            now = max(now, dp[i-num[aa]]+1)
    dp[i] = now

answer = ''
for i in range(dp[-1]):
    for aa in a:
        if N >= num[aa]:
            if dp[N-num[aa]] == dp[N] - 1:
                answer += str(aa)
                N -= num[aa]
                break
print(answer)