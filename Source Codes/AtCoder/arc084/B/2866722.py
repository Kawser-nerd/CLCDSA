from collections import deque
K = int(input())
G = [[] for i in range(K)]
for i in range(K):
    G[i].append(((i+1) % K, 1))
    G[i].append((10*i % K, 0))

visited = [0] * K
queue = deque([(1, 1)])

# 01BFS
while queue:
    now, cost = queue.popleft()
    if now == 0:
        print(cost)
        break

    visited[now] = 1
    for n, c in G[now]:
        if visited[n]:
            continue

        if c == 0:
            queue.appendleft((n, cost))
        else:
            queue.append((n, cost+1))