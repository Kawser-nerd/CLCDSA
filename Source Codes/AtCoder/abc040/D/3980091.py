N, M = map(int, input().split())
 
rank = [0] * (N + 1)
par = [i for i in range(N + 1)]
size = [1] * (N + 1)
 
 
def find(x):
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]
 
 
def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
 
    if rank[x] < rank[y]:
        par[x] = y
        size[y] += size[x]
 
    else:
        par[y] = x
        size[x] += size[y]
        if rank[x] == rank[y]:
            rank[x] += 1
 
 
def same(x, y):
    return find(x) == find(y)
 
 
def get(x):
    return size[find(x)]
 
 
road = []
for i in range(M):
    a, b, c = map(int, input().split())
    road.append((a, b, c))
 
Q = []
q = int(input())
for i in range(q):
    v, w = map(int, input().split())
    Q.append((i, v, w))
 
 
Q = sorted(Q, key=lambda x: x[2], reverse=True)
ans = [0] * q
road = sorted(road, key=lambda x: x[2], reverse=True)
j = 0
for i in range(len(Q)):
    while j < M and road[j][2] > Q[i][2]:
        unite(road[j][0], road[j][1])
        j += 1
 
    ans[Q[i][0]] = get(Q[i][1])
 
for a in ans:
    print(a)