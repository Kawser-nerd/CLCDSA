from collections import deque
N = int(input())
edge = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    edge[a - 1].append(b - 1)
    edge[b - 1].append(a - 1)
d = [[-1] * N for _ in range(2)]
for i in range(2):
    d[i][i * (N - 1)] = 0
    q = deque([i * (N - 1)])
    while len(q) > 0:
        u = q.popleft()
        for v in edge[u]:
            if d[i][v] > -1:
                continue
            d[i][v] = d[i][u] + 1
            q.append(v)
S = 0
F = 0
for i in range(N):
    if d[0][i] > d[1][i]:
        S += 1
    else:
        F += 1
if F > S:
    print("Fennec")
else:
    print("Snuke")