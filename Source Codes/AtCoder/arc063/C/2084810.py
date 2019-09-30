import sys
sys.setrecursionlimit(10**6)
N = int(input())
G = [[] for i in range(N)]
for i in range(N-1):
    A, B = map(int, input().split())
    G[A-1].append(B-1)
    G[B-1].append(A-1)
M = {}
K = int(input())
for i in range(K):
    V, P = map(int, input().split())
    M[V-1] = P
memo = [0]*N
def dfs(v, p, x, y):
    if v in M:
        x = y = M[v]
    x0 = x; y0 = y
    for w in G[v]:
        if p == w:
            continue
        s, t = dfs(w, v, x-1, y+1)
        x0 = max(x0, s-1); y0 = min(y0, t+1)
    memo[v] = x0, y0
    return x0, y0
def dfs1(v, p, x, y, c):
    if v in M:
        x = y = M[v]
        if c != (M[v] % 2):
            return 0
    x0, y0 = memo[v]
    x = max(x, x0); y = min(y, y0)
    for w in G[v]:
        if p == w:
            continue
        if not dfs1(w, v, x-1, y+1, c^1):
            return 0
    memo[v] = x, y
    return 1

INF = 10**18
f = list(M.keys())[0]
dfs(f, -1, -INF, INF)
ok = dfs1(f, -1, -INF, INF, M[f]%2)
for i in range(N):
    x, y = memo[i]
    if not x <= y:
        ok = 0
if ok:
    print('Yes')
    print(*map(lambda x: x[1], memo), sep='\n')
else:
    print('No')