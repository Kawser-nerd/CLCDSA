N, A, B = map(int, input().split())

print(A * (N - min(5, N)) + B * min(5, N))