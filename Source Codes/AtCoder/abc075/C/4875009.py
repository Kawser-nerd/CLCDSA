N, M = map(int, input().split())
D = [list() for i in range(N)]
A = []
B = []
for i in range(M):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
    D[a-1].append(b-1)
    D[b-1].append(a-1)
d = [0]*N
d[0] = 1
cnt = 0


def dfs(x):
    for i in D[x]:
        if d[i] == 0:
            d[i] = 1
            dfs(i)


for i in range(M):
    D[A[i] - 1].remove(B[i] - 1)
    D[B[i] - 1].remove(A[i] - 1)

    d = [0]*N
    d[0] = 1
    dfs(0)

    if all(d) is False:
        cnt += 1
    D[A[i] - 1].append(B[i] - 1)
    D[B[i] - 1].append(A[i] - 1)

print(cnt)