N, K = [int(_) for _ in input().split()]
ans = 0
for mod in range(K + 1, N + 1):
    ans += (mod - K) * (N // mod) + max(N % mod - max(K - 1, 0), 0)
print(ans)