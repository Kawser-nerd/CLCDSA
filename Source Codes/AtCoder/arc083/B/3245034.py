import numpy as np
N=int(input())
dist=[[0.0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    for j,x in enumerate(map(int,input().split())):
        dist[i][j]=float(x)
dist = np.array(dist)
for i in range(N):
    dist[i,i] = float('inf')
ans=0
for i in range(N):
    for j in range(i+1,N):
        min_=min(dist[i]+dist[j])
        if min_<dist[i,j]:
            ans=-1
            break
        elif min_>dist[i,j]:
            ans+=dist[i,j]
    if ans <0:
        break
print(int(ans))