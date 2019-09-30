N, M = map(int, input().split())
ES = []
D = [{} for i in range(N)]

*parent, = range(M)
def root(x):
    if x == parent[x]:
        return x
    parent[x] = y = root(parent[x])
    return y
def unite(x, y):
    px = root(x); py = root(y)
    if px < py:
        parent[py] = px
    else:
        parent[px] = py

E = {}
for i in range(M):
    p, q, c = map(int, input().split()); p -= 1; q -= 1
    ES.append((p, q, c))
    if c in D[p]:
        unite(D[p][c], i)
    else:
        D[p][c] = i
    E.setdefault(p, set()).add(c)
    if c in D[q]:
        unite(D[q][c], i)
    else:
        D[q][c] = i
    E.setdefault(q, set()).add(c)
P = {}
for i in range(M):
    p, q, c = ES[i]
    s = P.setdefault(root(i), set())
    s.add(p); s.add(q)

from collections import deque
que = deque([(0, 0, 0)])
INF = 10**18
dist = [INF]*N
dist[0] = 0
gdist = [INF]*M

while que:
    cost, v, t = que.popleft()
    if t:
        # edge
        if gdist[v] < cost or v not in P:
            continue
        for w in P[v]:
            if cost + 1 < dist[w]:
                dist[w] = cost + 1
                que.append((cost + 1, w, 0))
    else:
        # node
        if dist[v] < cost or v not in E:
            continue
        for w in D[v].values():
            w = root(w)
            if cost < gdist[w]:
                gdist[w] = cost
                que.appendleft((cost, w, 1))

print(dist[N-1] if dist[N-1] < INF else -1)