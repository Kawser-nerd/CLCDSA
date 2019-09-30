# ???????
N = int(input())
D = [list(map(int, input().split(' '))) for _ in range(N)]
Q = int(input())
P = [int(input()) for _ in range(Q)]

# ???????????????
S_BR = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        # ???????????
        for x in range(i, N):
            for y in range(j, N):
                S_BR[i][j] += D[x][y]

# ??????????
S = [0] * N * N
for i in range(N):
    for j in range(N):
        for x in range(i+1, N+1):
            for y in range(j+1, N+1):
                # ???????
                # ???????? - ???????? - ???????? + ????????
                if y < N and x < N:
                    s = S_BR[i][j]-S_BR[i][y]-S_BR[x][j]+S_BR[x][y]
                elif y >= N and x >= N:
                    s = S_BR[i][j]
                elif y >= N:
                    s = S_BR[i][j]-S_BR[x][j]
                elif x >= N:
                    s = S_BR[i][j]-S_BR[i][y]
                else:
                    raise RuntimeError
                S[(x-i)*(y-j)-1] = max(S[(x-i)*(y-j)-1], s)

# n?n-1????????n-1??????????n?????????
for i in range(1, len(S)):
    S[i] = max(S[i-1], S[i])

# ??
[print(S[p-1]) for p in P]