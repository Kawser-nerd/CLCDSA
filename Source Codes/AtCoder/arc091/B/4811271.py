N, K = map(int, input().split())
if K == 0:
    ans = N * N
else:
    ans = 0
    for b in range(K + 1, N + 1):
        ans += (b - K) * (N // b) + max(0, N % b - K + 1)
print(ans)