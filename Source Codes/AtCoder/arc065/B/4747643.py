def init(par, n):
    global rank
    par = [i for i in range(n)]
    rank = [0] * n

def find(par, x):
    if par[x] == x:
        return x
    else:
        par[x] = find(par, par[x])
        return par[x]

def unite(par, x, y):
    global rank
    x = find(par, x)
    y = find(par, y)
    if x == y:
        return
    if rank[x] < rank[y]:
        par[x] = y
    else:
        par[y] = x
        if rank[x] == rank[y]:
            rank[x] += 1

N, K, L = map(int, input().split())
roads = [i for i in range(N)]
rank = [0] * N
for i in range(K):
    p, q = map(int, input().split())
    unite(roads, p - 1, q - 1)
rails = [i for i in range(N)]
rank = [0] * N
for i in range(L):
    p, q = map(int, input().split())
    unite(rails, p - 1, q - 1)
d = {}
for i in range(N):
    d[find(roads, i), find(rails, i)] = d.get((find(roads, i), find(rails, i)), 0) + 1
for i in range(N):
    print(d[find(roads, i), find(rails, i)], end = " ")
print()