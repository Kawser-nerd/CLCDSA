N, M = map(int, input().split())
E = {i: [] for i in range(1, N+1)}
for _ in range(M):
    u, v = map(int, input().split())
    E[u].append(v)
    E[v].append(u)

visited = {i: False for i in range(1, N+1)}
counter = 0

while False in visited.values():
    stk = [(list(visited.values()).index(False) + 1, -1)]
    flag = True
    while stk:
        v, p = stk.pop()
        if visited[v]:
            flag = False
            continue
        visited[v] = True
        for u in E[v]:
            if u != p:
                stk.append((u, v))
    counter += flag
print(counter)