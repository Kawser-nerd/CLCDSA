inf = float('inf')

N,M = map(int,input().split())
info = []
for _ in range(M):
    a,b,c = map(int,input().split())
    a -= 1; b -= 1
    info.append((a,b,c))
 
dist = [-inf for _ in range(N)]
dist[0] = 0
for i in range(N):
    for v,nv,w in info:
        if dist[nv] < dist[v] + w:
            dist[nv] = dist[v] + w
            if i == N-1 and nv == N-1:
                print("inf")
                exit()
ans = dist[N-1]
print(ans)