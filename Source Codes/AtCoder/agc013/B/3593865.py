def inpl(): return [int(i) for i in input().split()]
def next(v):
    for i in edge[v]:
        if visited[i]:
            continue
        visited[i] = True
        return i
    return -1

from collections import defaultdict
edge = defaultdict(lambda: [])
N, M = inpl()
visited = [False for _ in range(N+1)]
visited[1] = True
for _ in range(M):
    A,B = inpl()
    edge[A].append(B)
    edge[B].append(A)
v = 1
nv = 1
path = [1]
while nv >= 0:
    nv = next(v)
    path.append(nv)
    v = nv
path.pop()
path = list(reversed(path))
v = 1
nv = 1
while nv >= 0:
    nv = next(v)
    path.append(nv)
    v = nv
path.pop()
print(len(path))
print(*path)