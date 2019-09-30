N = int(input())
G = [[] for i in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

from collections import deque
def bfs(v):
    que = deque([v])
    dist = {v: 0}
    prev = {v: v}
    while que:
        u = que.popleft()
        d = dist[u]
        for w in G[u]:
            if w in dist:
                continue
            dist[w] = d + 1
            prev[w] = u
            que.append(w)
    w = u
    D = []
    while w != v:
        D.append(w)
        w = prev[w]
    D.append(v)
    return u, D

from collections import deque
def solve(u, v = -1):
    que = deque([u])
    if v != -1:
        que.append(v)
    used = set([u, v])
    D = {v: 0, u: 0}
    E = {}
    if v != -1:
        E[0] = max(len(G[v]), len(G[u]))-1
    else:
        E[0] = len(G[u])
    x = v
    while que:
        v = que.popleft()
        d = D[v]
        for w in G[v]:
            if w in used:
                continue
            D[w] = d + 1
            que.append(w)
            used.add(w)
            E[d+1] = max(E.get(d+1, 0), len(G[w])-1)
    res = 2 if x != -1 else 1
    for v in E.values():
        if v: res *= v
    return res

D = bfs(bfs(0)[0])[1]
L = len(D)

col = (L + 1) // 2

if L % 2 == 1:
    ans = 10**18
    v = D[L//2]
    for w in G[v]:
        ans = min(ans, solve(v, w))
    ans = min(ans, solve(v))
else:
    v = D[L//2-1]; w = D[L//2]
    ans = solve(v, w)
print(col, ans)