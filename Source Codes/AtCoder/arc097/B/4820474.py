def init(n):
    global par, rank
    par = [i for i in range(n)]
    rank = [0] * n

def find(x):
    global par
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]

def unite(x, y):
    global par, rank
    x = find(x)
    y = find(y)
    if x == y:
        return
    if rank[x] < rank[y]:
        par[x] = y
    else:
        par[y] = x
        if rank[x] == rank[y]:
            rank[x] += 1

def same(x, y):
    return find(x) == find(y)

N, M = map(int, input().split())
init(N)
p = list(map(int, input().split()))
for _ in range(M):
    x, y = map(int, input().split())
    unite(x - 1, y - 1)
ans = 0
for i in range(N):
    if same(i, p[i] - 1):
        ans += 1
print(ans)