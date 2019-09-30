N = int(input())
A = list(map(int, input().split()))

if N % 2:
    index = list(range(N - 1, -1, -2)) + list(range(1, N, 2))
else:
    index = list(range(N - 1, 0, -2)) + list(range(0, N, 2))

print(*list(map(lambda i: A[i], index)))