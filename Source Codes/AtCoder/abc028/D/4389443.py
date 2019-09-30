N, K = map(int, input().split())
print(((K-1) * (N-K) * 6 + (N-1)*3 + 1) / N**3)