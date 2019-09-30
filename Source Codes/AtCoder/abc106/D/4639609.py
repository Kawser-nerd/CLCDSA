N, M, Q = map(int, input().split())

A = [[0] * (N + 1) for i in range(N + 1)]
for i in range(M):
    l, r = map(int, input().split())
    A[l][r] += 1
    
for i in range(1, N + 1):
    for j in range(1, N + 1):
        A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j -1]
        
for i in range(Q):
    p, q = map(int, input().split())
    print(A[q][q] - A[q][p - 1] - A[p - 1][q] + A[p - 1][p - 1])