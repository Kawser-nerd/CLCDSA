N, M = [int(i) for i in input().split()]
p_ls = [int(i) - 1 for i in input().split()]

par = [i for i in range(N)]
rank = [1 for i in range(N)]

def find(x):
    if par[x] == x:
        return x
    else:
        return find(par[x])

def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        pass
    else:
        if rank[x] > rank[y]:
            par[y] = x
            rank[x] += rank[y]
        else:
            par[x] = par[y]
            rank[y] += rank[x]

def is_same(x, y):
    if find(x) == find(y):
        return True
    else:
        return False

data_ls = list()
for i in range(M):
    x, y = [int(i)-1 for i in input().split()]
    if is_same(x, y):
        pass
    else:
        unite(x, y)
cnt = 0
for i in range(N):
    if is_same(i, p_ls[i]):
        cnt += 1
print(cnt)