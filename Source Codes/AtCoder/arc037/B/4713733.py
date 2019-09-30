N, M = map(int, input().split())
E = {i: [] for i in range(1, N+1)}
for _ in range(M):
    u, v = map(int, input().split())
    E[u].append(v)
    E[v].append(u)

visited = {i: -1 for i in range(1, N+1)}
counter = 0

while -1 in visited.values():
    stk = [(list(visited.values()).index(-1) + 1, 0)]
    flag = True
    while stk:
        v, depth = stk.pop()
        if visited[v] != -1:
            if depth - visited[v] >= 3:
                flag = False
            continue
        visited[v] = depth
        for u in E[v]:
            stk.append((u, depth + 1))
    counter += flag
print(counter)