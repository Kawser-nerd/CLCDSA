A, T, k = map(int, input().split())
CS = []
D = [0 for i in range(T+1)]
for i in range(A):
    N = int(input())
    C = list(map(int, input().split()))
    CS.append(C)
    v = 1 << i
    for c in C:
        D[c] |= v

E = [[] for i in range(A)]

IDX = [C.index for C in CS]

M = int(input())
for i in range(M):
    c1, c2, cost = map(int, input().split())
    v = D[c1] & D[c2]
    i = len(bin(v & -v))-3
    index = IDX[i]
    E[i].append((index(c1), index(c2), cost))

from itertools import combinations

def root(p, x):
    if p[x] == x:
        return x
    p[x] = y = root(p, p[x])
    return y
def unite(p, x, y):
    px = root(p, x)
    py = root(p, y)
    if px == py:
        return 0
    if px < py:
        p[py] = px
    else:
        p[px] = py
    return 1

def make(N, E):
    rN = range(N)
    D = {}
    csA = sum(cost for u, v, cost in E)
    for P in combinations(E, N-1):
        *p, = rN
        ok = 1
        for u, v, cost in P:
            if not unite(p, u, v):
                ok = 0
        if ok:
            cs = sum(cost for u, v, cost in P)
            D[csA-cs] = D.get(csA-cs, 0) + 1
    return sorted(D.items())

lim = 0
S = {0: 1}
for i in range(A):
    P = make(len(CS[i]), E[i])
    T = {}
    get = T.get
    l = 0
    m = max(S) + P[0][0]
    for s, u in S.items():
        for p, c in P:
            if lim and s+p > m:
                break
            T[s+p] = get(s+p, 0) + u*c
            l += u*c
    if l > k:
        for q in sorted(T, reverse=1):
            if l-T[q] <= k:
                break
            l -= T[q]
            del T[q]
        lim = 1
    S = T
ans = -1
if k <= l:
    for p, c in sorted(S.items()):
        if k <= c:
            ans = p
            break
        k -= c
print(ans)