N, M = map(int, input().split())
road = []
r_append = road.append
for i in range(M):
    a, b, c = map(int, input().split())
    r_append((a, b, c))

Q = int(input())
query = []
q_append = query.append
for i in range(Q):
    v, w = map(int, input().split())
    q_append((i, v, w))

road = sorted(road, key=lambda x: x[2], reverse=True)

parent = [i for i in range(N + 1)]
size = [1] * (N + 1)


def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


def union(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    else:
        parent[y] = x
        size[x] += size[y]


def get_size(x):
    return size[find(x)]


ans = [0] * Q
a, b, y = road[0]
i = 0

for q in sorted(query, key=lambda x: x[2], reverse=True):
    j, v, w = q
    while i < M and y > w:
        union(a, b)
        i += 1
        if i == M:
            break
        a, b, y = road[i]
    ans[j] = get_size(v)

for i in range(Q):
    print(ans[i])