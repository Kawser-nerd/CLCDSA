N, X = map(int, input().split())
*H, = map(int, input().split())

G = [[] for i in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

used = [0]*N
def dfs(v, p, d):
    r = H[v]
    for w in G[v]:
        if w == p:
            continue
        r |= dfs(w, v, d+1)
    used[v] = r
    return r
dfs(X-1, -1, 0)
res = 0
for v in range(N):
    if used[v]:
        if v != X-1:
            res += 2
print(res)