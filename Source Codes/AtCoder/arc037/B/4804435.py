N,M = map(int,input().split())
E  = {i:[] for i in range(N)}
for i in range(M):
    u,v = map(int,input().split())
    u,v = u-1,v-1
    E[u].append(v)
    E[v].append(u)
visited = {i:False for i in range(N)}
counter = 0

while False in visited.values():
    stk = [(list(visited.values()).index(False),-1)]
    flag = 1
    while stk:
        v,p = stk.pop()
        if visited[v]:
            flag = 0
            continue
        visited[v] = True
        for u in E[v]:
            if u !=p:
                stk.append((u,v))
    counter += flag
print(counter)