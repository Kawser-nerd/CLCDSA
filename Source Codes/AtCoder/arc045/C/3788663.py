import sys
from collections import Counter, deque

N, X = map(int, input().split())
edges = [[] for _ in [0]*(N+1)]
for x, y, c in (map(int, l.split()) for l in sys.stdin):
    edges[x].append((y, c))
    edges[y].append((x, c))

xor_count, answer, dq = Counter({0: 1}), 0, deque(edges[1])
popleft, append = dq.popleft, dq.append
visited = [0, 1] + [0]*N
for v, _ in edges[1]:
    visited[v] = 1
    
while dq:
    v, cost = popleft()
    answer += xor_count[X ^ cost]
    xor_count[cost] += 1

    for to_v, to_cost in edges[v]:
        if visited[to_v]:
            continue
        visited[to_v] = 1
        append((to_v, cost ^ to_cost))

print(answer)