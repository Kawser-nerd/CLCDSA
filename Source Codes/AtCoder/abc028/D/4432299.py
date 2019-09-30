N, K = map(int, input().split())
print((1 + 3 * (N - 1) + 6 * (N - K) * (K - 1)) / N**3)