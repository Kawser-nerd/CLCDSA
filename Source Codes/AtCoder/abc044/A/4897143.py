N, K, X, Y = (int(input()) for _ in range(4))
if N > K:
    result = K * X + (N-K) * Y
else:
    result = N * X
print(result)