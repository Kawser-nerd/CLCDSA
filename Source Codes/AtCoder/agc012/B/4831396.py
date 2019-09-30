n, m  = map(int, input().split())
g     = {}
used  = {i:[False for _ in range(11)] for i in range(n)}
color     = [0  for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    u-=1
    v-=1
    if u not in g:
        g[u] = []
    if v not in g:
        g[v] = []
    g[u].append(v)
    g[v].append(u)
    
q = int(input())
Q = []

for _ in range(q):
    node, dis, col = map(int, input().split())
    Q.append([node-1, dis, col])
Q = Q[::-1]

def bfs(now, dist, col):
    if dist < 0:
        return
    
    if used[now][dist]:
        return
 
    used[now][dist] = True
    
    if not color[now]:
        color[now] = col
 
    if now in g:
        for x in g[now]:
            bfs(x, dist - 1, col)
            
for node, dis, col in Q:
    bfs(node, dis, col)

for x in color:
    print(x)