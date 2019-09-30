N = int(input())
A = int(input())
G = [[] for i in range(N)]
D = [0]*N
for i in range(A):
    x, y = map(int, input().split())
    G[y-1].append(x-1)
    D[x-1] += 1
B = int(input())
E = []
for i in range(B):
    u, v = map(int, input().split())
    E.append((u-1, v-1))

def solve(G, D, U):
    update = 1
    r = 0
    while update:
        update = 0
        for v in range(N):
            if D[v] == 0 and U[v] is None:
                for w in G[v]:
                    D[w] -= 1
                update = 1
                U[v] = 1
                r += 1
    return r

if B == 0:
    ans = solve(G, D, [None]*N)
else:
    from itertools import product
    ans = 0
    for P in product([0, 1], repeat=B):
        G0 = [e[:] for e in G]
        D0 = D[:]
        U = [None]*N
        for p, (u, v) in zip(P, E):
            if p:
                G0[u].append(v)
                D0[v] += 1
            else:
                U[u] = 0
        ans = max(ans, solve(G0, D0, U))
print(ans)