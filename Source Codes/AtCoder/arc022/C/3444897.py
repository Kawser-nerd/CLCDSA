from collections import deque
N = int(input())
G = [[] for i in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    G[a].append(b)
    G[b].append(a)
INF = float("inf")


def bfs(s):
    d = [INF] * N
    d[s] = 0
    rec = [0, 0]
    que = deque([s])
    while que:
        v = que.popleft()

        for w in G[v]:
            if d[w] != INF:
                continue
            d[w] = d[v] + 1
            que.append(w)
            if rec[0] < d[w]:
                rec[0] = d[w]
                rec[1] = w

    return rec[1]


q = bfs(0)
p = bfs(q)
print(q + 1, p + 1)