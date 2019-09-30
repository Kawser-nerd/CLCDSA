def root(x):
    if uf[x] == x:
        return x
    uf[x] = root(uf[x])
    return uf[x]

def same(x, y):
    return root(x) == root(y)

def unite(x, y):
    rx = root(x)
    ry = root(y)
    if rx == ry:
        return
    uf[rx] = ry

N, M = map(int,input().split())
edge = []
for i in range(M):
    edge.append(list(map(int,input().split())))

cnt = 0
for i in range(M):
    uf = [i for i in range(N+1)]
    for j in range(M):
        if i != j:
            unite(edge[j][0], edge[j][1])
    for j in range(N):
        if not same(1, j+1):
            cnt += 1
            break
print(str(cnt))