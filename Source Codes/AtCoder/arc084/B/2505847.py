from collections import deque
K=int(input())
reached=[0 for i in range(K)]
reached[1]=1
dist=[0 for i in range(K)]
q=deque([])
q.append(1)
while(len(q)>0):
    r=q.popleft()
    v=(r+1)%K
    reached[r]=1
    if (reached[v]==0):
        q.append(v)
        dist[v]=dist[r]+1
    v=(r*10)%K
    if (reached[v]==0):
        q.appendleft(v)
        dist[v]=dist[r]
    if (reached[0]==1):
        break
print(dist[0]+1)