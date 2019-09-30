N, M = map(int, input().split())
G = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    G[a].append(b)
    G[b].append(a)

Q = int(input())
C = []
for i in range(Q):
    v, d, c = map(int, input().split())
    C.append((v - 1, d, c))
dp = [[0, -1] for i in range(N)]


def paint(v, d, c):
    x, y = dp[v]
    if d <= y:
        return
    if x == 0:
        dp[v] = c, d
    else:
        dp[v] = x, d

    if d == 0:
        return
    for i in G[v]:
        paint(i, d - 1, c)


for v, d, c in reversed(C):
    paint(v, d, c)

for k in dp:
    print(k[0])