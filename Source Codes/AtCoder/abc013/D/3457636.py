N, M, D = map(int, input().split())
A = list(map(int, input().split()))
T = [i for i in range(N + 1)]
P = [[0] * (N + 1) for i in range(30)]
for i in range(M - 1, -1, -1):
    T[A[i]], T[A[i] + 1] = T[A[i] + 1], T[A[i]]

P[0] = T
for i in range(1, 30):
    for j in range(1, N + 1):
        P[i][j] = P[i - 1][P[i - 1][j]]

Q = [i for i in range(N + 1)]
for i in range(29, -1, -1):
    if D == 0:
        break
    if D >= 2 ** i:
        D -= 2 ** i
        for j in range(1, N + 1):
            Q[j] = P[i][Q[j]]

for k in range(1, N + 1):
    print(Q[k])