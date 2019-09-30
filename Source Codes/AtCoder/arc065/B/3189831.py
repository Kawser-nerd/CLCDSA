from collections import Counter

def root(par, x):
    if par[x] == x:
        return x
    par[x] = root(par, par[x])
    return par[x]

def unite(par, x, y):
    rx, ry = root(par, x), root(par, y)
    if rx == ry:
        return

    if rank[rx] > rank[ry]:
        par[ry] = rx
    elif rank[rx] < rank[ry]:
        par[rx] = ry
    else:
        par[ry] = rx
        rank[rx] += 1
        
N, K, L = map(int, input().split())

rank = [1] * N
roads = [i for i in range(N)]
for _ in range(K):
    unite(roads, *map(lambda x: int(x) - 1, input().split()))

rank = [1] * N
rails = [i for i in range(N)]
for _ in range(L):
    unite(rails, *map(lambda x: int(x) - 1, input().split()))

count = Counter((root(roads, i), root(rails, i)) for i in range(N))
print(*(count[root(roads, i), root(rails, i)] for i in range(N)))