import sys
from collections import deque

N, K = map(int, input().split())
edges = [[] for _ in [0]*N]
for a, b in (map(int, l.split()) for l in sys.stdin):
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)


def search(v_a):
    dq = deque([(v, 0) for v in v_a])
    popleft, append = dq.popleft, dq.append
    visited = [0]*N
    visited[v_a[0]] = visited[v_a[-1]] = 1

    while dq:
        v, dist = popleft()
        if dist >= K//2:
            continue
        for to_v in edges[v]:
            if not visited[to_v]:
                visited[to_v] = 1
                append((to_v, dist+1))

    return N-sum(visited)


if K % 2 == 0:
    print(min(search([v]) for v in range(N)))
else:
    edge_pair = {(v1, v2) if v1 < v2 else (v2, v1) for v1, edge in enumerate(edges) for v2 in edge}
    print(min(search(edge) for edge in edge_pair))