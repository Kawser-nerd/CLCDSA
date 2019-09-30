# coding: utf-8

N, M = map(int, input().split())
sum = {}
ans = 0

for i in range(0, N):
    K = list(map(int, input().split()))
    for j in range(1, K[0] + 1):
        if K[j] not in sum:
            sum[K[j]] = 1
        else:
            sum[K[j]] += 1

for k in sum:
    if sum[k] == N:
        ans += 1
print(ans)