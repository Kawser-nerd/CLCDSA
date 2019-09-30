N, A, B = map(int, input().split())
print((N - 5) * A + 5 * B if N > 5 else N * B)