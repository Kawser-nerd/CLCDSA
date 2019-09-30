from collections import deque
from collections import defaultdict

G = defaultdict(list)
N, M = map(int, input().split())
color = [0] * (N + 1)

for _ in range(M):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)
Q = int(input())

data = [list(map(int, input().split())) for _ in range(Q)]
data.reverse()
color_d = [-1] * (N + 1)

for v, d, c in data:
    if color_d[v] >= d:
        pass
    # BFS
    deq = deque([v])
    if color[v] == 0:
        color[v] = c
    color_d[v] = d
    while len(deq) > 0:
        s = deq.popleft()
        for t in G[s]:
            if color_d[t] >= color_d[s] - 1:
                pass
            else:
                color_d[t] = color_d[s] - 1
                if color[t] == 0:
                    color[t] = c
                if color_d[t] > 0:
                    deq.append(t)

for n in range(1, N + 1):
    print(color[n])