N, M = map(int, input().split())
P = list(map(lambda x: int(x) - 1, input().split()))
rank = [0] * N
parent = [i for i in range(N)]


def find(i):
    if parent[i] == i:
        return i
    else:
        parent[i] = find(parent[i])
        return parent[i]


def same(x, y):
    return find(x) == find(y)


def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return

    if rank[x] > rank[y]:
        parent[y] = x
    else:
        parent[x] = y
        if rank[x] == rank[y]:
            rank[y] += 1


for i in range(M):
    x, y = map(int, input().split())
    unite(x - 1, y - 1)

num = 0
for i in range(N):
    num += same(i, P[i])

print(num)