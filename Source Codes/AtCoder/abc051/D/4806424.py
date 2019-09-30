import sys
input = sys.stdin.readline

inf = float('inf')

# dist[i][j]: i??j?????,  n:???
def warshall_floyd(dist,n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i == j:
                    dist[i][j] = 0
                elif dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

N,M = map(int,input().split())
edges = []
ad = [[inf]*N for _ in range(N)]
for _ in range(M):
    a,b,c = map(int,input().split())
    a -= 1;  b -= 1
    edges.append((a,b,c))
    ad[a][b] = c
    ad[b][a] = c

warshall_floyd(ad,N)
ans = M

for a,b,c in edges:
    if a > b:
        a,b = b,a
    for s in range(N):
        for e in range(s+1,N):
            if ad[s][a] + c + ad[b][e] == ad[s][e]:
                ans -= 1
                break
        else:
            continue
        break

print(ans)