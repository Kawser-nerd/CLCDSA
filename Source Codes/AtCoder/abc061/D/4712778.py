#???????????????????????
N, M = map(int, input().split())
Edges = []
for i in range(M):
    a, b, c = map(int, input().split())
    a, b = a - 1, b - 1
    c = -c
    Edges.append([a, b, c])

dist = [float('inf')] * N
dist[0] = 0

for i in range(N):
    for fr, to, cost in Edges:
        if (dist[fr] != float('inf')) and (dist[to] > dist[fr] + cost):
            dist[to] = dist[fr] + cost
            if (i == N - 1) & (to == N - 1):
                print('inf')
                exit()

print(-dist[-1])