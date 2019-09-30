N,M = map(int,input().split())
edge =[[] for _ in range(N+1)]
for _ in range(M):
    l,r,d = map(int,input().split())
    edge[l].append([r,d])
    edge[r].append([l,-d])
G = [None]*(N+1)
ok = True
stack = []
for x in range(1,N+1):
    if G[x] is not None: continue
    G[x] = 0
    stack = [x]
    while stack:
        v = stack.pop()
        for to,d in edge[v]:
            if G[to] is None:
                G[to] = G[v] + d
                stack.append(to)
            else:
                if G[to] != G[v] + d:
                    ok = False
                    break
    if ok == False:
        break
print('Yes' if ok else 'No')