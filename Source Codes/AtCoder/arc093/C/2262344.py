N, M = map(int, input().split())
X = int(input())
E = []
C = {}
for i in range(M):
    u, v, w = map(int, input().split())
    E.append((w, u-1, v-1))
    C[w] = C.get(w, 0) + 1
E.sort()

*p, = range(N)
def root(x):
    if x == p[x]:
        return x
    y = p[x] = root(p[x])
    return y
def unite(x, y):
    px = root(x); py = root(y)
    if px == py:
        return 0
    if px < py:
        p[py] = px
    else:
        p[px] = py
    return 1

MOD = 10**9 + 7

G0 = [[] for i in range(N)]
K = 0
last = None
U = [0]*M
cost = 0
for i in range(M):
    w, u, v = E[i]
    if unite(u, v):
        cost += w
        U[i] = 1
        if last != w:
            K += C[w]
        G0[u].append((v, w))
        G0[v].append((u, w))
        last = w
def dfs0(u, p, t, cost):
    if u == t:
        return 0
    for v, w in G0[u]:
        if v == p:
            continue
        r = dfs0(v, u, t, cost)
        if r is not None:
            return r | (w == cost)
    return None
def dfs1(u, p, t):
    if u == t:
        return 0
    for v, w in G0[u]:
        if v == p:
            continue
        r = dfs1(v, u, t)
        if r is not None:
            return max(r, w)
    return None

if X - cost < 0:
    print(0)
    exit(0)

K = 0
for i in range(M):
    if U[i]:
        K += 1
        continue
    w, u, v = E[i]
    if dfs0(u, -1, v, w):
        K += 1
        U[i] = 1
if cost == X:
    ans = ((pow(2, K, MOD) - 2)*pow(2, M-K, MOD)) % MOD
    print(ans)
    exit(0)

L = 0
G = 0
for i in range(M):
    w, u, v = E[i]
    if last + (X - cost) < w:
        break
    G += 1
    if U[i]:
        continue
    r = dfs1(u, -1, v) + (X - cost)
    if r == w:
        L += 1
    elif r < w:
        G -= 1

ans = (2*(pow(2, L, MOD)-1)*pow(2, M-G, MOD)) % MOD
print(ans)