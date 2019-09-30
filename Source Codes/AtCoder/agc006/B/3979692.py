N, x = [int(_) for _ in input().split()]

A = list(range(N + 1, 2 * N)) + list(range(1, N + 1))
if x in [1, 2 * N - 1]:
    print('No')
else:
    print('Yes')
    if x > N:
        A[x - N - 1], A[N - 1] = A[N - 1], A[x - N - 1]
    else:
        A[x + N - 2], A[N - 1] = A[N - 1], A[x + N - 2]
    print(*A, sep='\n')