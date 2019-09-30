# seishin.py
from collections import deque
N = int(input())
*P, = map(int, input().split())
MOD = 10**9 + 7

G = [[] for i in range(N+1)]
U = [0]*(N+1)
C = [0]*(N+1)
for i, p in enumerate(P):
    G[p].append(i+1)
    U[i+1] = u = U[p]+1
    C[u] += 1
Q = [None]*(N+1)
PP = {}
def pp(k):
    if k not in PP:
        PP[k] = p = pow(2, k, MOD)
        return p
    return PP[k]
L = [0]*(N+1)

ept = []
sz = L.__getitem__
for i in range(N, -1, -1):
    g = G[i]
    if not g:
        continue

    # ?????deque????
    g.sort(key=sz, reverse=1)
    k = len(g)
    e = [pp(k) - k, k, 0]

    g0 = g[0]
    L[i] = L[g0] + 1
    if L[g0] == 0:
        Q[i] = deque([e])
        continue
    Q[i] = R = Q[g0]
    if k > 1:
        # a0 <- a2
        for s, r in zip(Q[g[1]] or ept, R):
            r[0] += r[2]; r[2] = 0

        for j in g[1:]:
            S = Q[j]
            if not S:
                break

            # deque???????????????????
            for (a0, a1, a2), r in zip(S, R):
                b0, b1, b2 = r; a0 += a2
                r[0] = a0*b0 % MOD
                r[1] = (a0*b1 + a1*b0) % MOD
                r[2] = ((a0+a1)*b2 + a1*b1) % MOD
    R.appendleft(e)
print((pp(N) + sum(pp(N+1-c) * a1 % MOD for (a0, a1, a2), c in zip(Q[0], C[1:]))) % MOD)