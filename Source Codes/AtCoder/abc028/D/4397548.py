N, K = map(int, input().split())

# 1? K
ans = (N - K) * (K - 1) * 6

# 2? K
ans += (N - 1) * 3

# 3? K
ans += 1

print(ans / pow(N, 3))