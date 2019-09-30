N, K = map(int, input().split())
ans = 0

# 3???K
ans += 1

# 2??K
ans += 3 * (N - 1)

# 1??K
ans += 6 * ((K - 1) * (N - K))

print(ans / (N ** 3))