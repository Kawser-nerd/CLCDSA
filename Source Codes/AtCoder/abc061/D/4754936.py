inf = float('inf')

# dist????: dist = [inf for _ in range(N)]; dist[start] = 0
# True - >?????, False -> start??end??????????????
def bellmanford(dist,edges,N,end):
    for i in range(N):
        for v ,nv, w in edges:
            if dist[nv] > dist[v] + w:
                dist[nv] = dist[v] + w
                # ???N???????N-1????
                # N???end????????????????????????
                if i == N-1 and nv == end:
                    return False
    return True

N,M = map(int,input().split())
info = []
for _ in range(M):
    a,b,c = map(int,input().split())
    a -= 1; b -= 1; c = -c
    info.append((a,b,c))
 
dist = [inf for _ in range(N)]
dist[0] = 0

flag = bellmanford(dist,info,N,N-1)
ans = -dist[N-1] if flag else "inf"
print(ans)