from collections import deque
MOD = 10**9+7
N = int(input())
a,b = map(lambda x:int(x)-1, input().split())
M = int(input())
edges = [[] for _ in range(N)]
for _ in range(M):
    x,y = map(lambda x:int(x)-1, input().split())
    edges[x].append(y)
    edges[y].append(x)
q = deque([a])
visited = [False]*N
visited[a] = True
depth = [-1]*N
depth[a] = 1
cnts = [0]*N
cnts[a] = 1
while q:
    cur = q.popleft()
    for nex in edges[cur]:
        if not visited[nex]:
            q.append(nex)
            visited[nex] = True
        if depth[nex]<0:
            depth[nex] = depth[cur]+1
        if depth[nex]==depth[cur]+1:
            cnts[nex] += cnts[cur]
            cnts[nex] %= MOD
    #print("cur: ", cur, cnts)
    #print(q)
    
print(cnts[b])
#print(depth)