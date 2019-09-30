import numpy as np
n=int(input())
a,b=map(int,input().split())
c=[[0]*(n+1) for i in range(n+1)]
for i in range(int(input())):
    x,y=map(int,input().split())
    c[x][y]+=1
    c[y][x]+=1
p=np.matrix(c)
q=p.copy()
while p[a,b]==0:
    p*=q
print(p[a,b]%(10**9+7))