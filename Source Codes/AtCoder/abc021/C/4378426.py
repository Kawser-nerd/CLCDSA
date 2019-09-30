import numpy as np
N=int(input())
a,b=map(int, input().split())
M=int(input())
Adjacency=np.zeros([N,N])
for i in range(M):
    x,y=map(int,input().split())
    Adjacency[x-1,y-1]=Adjacency[y-1,x-1]=1
a,b=a-1,b-1
walk=np.zeros([N,1])
walk[a]=1
for i in range(N):
    walk=np.dot(Adjacency,walk)
    if(walk[b]!=0):
        print(int(walk[b][0]%(1e9+7)))
        break