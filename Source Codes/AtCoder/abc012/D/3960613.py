def warhsall_floyd(graph):
    num_v = len(graph)
    for i in range(num_v):
        for j, c2 in enumerate(row[i] for row in graph):
            for k, (c1, c3) in enumerate(zip(graph[j], graph[i])):
                if c1 > c2 + c3:
                    graph[j][k] = c2 + c3
    return graph

N, M = map(int, input().split())
inf = float("inf")
graph = [[inf for _ in range(N)] for _ in range(N)]
for i in range(M):
    a, b, t = map(int, input().split())
    graph[a-1][b-1] = t
    graph[b-1][a-1] = t

graph = warhsall_floyd(graph)
ans = inf
for i in range(N):
    max_num = 0
    for j in range(N):
        if i == j:
            continue
        if graph[i][j] > max_num:
            max_num = graph[i][j]
    ans = min(max_num, ans)
print(ans)