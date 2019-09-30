from itertools import accumulate
from operator import add
N,K=map(int,input().split())
L=2*K
Map=[[0]*L for i in range(L)]

for i in range(N):
  x,y,c=input().split()
  x,y=int(x),int(y)
  if c=="W":
    x-=K
  x,y=x%L,y%L
  if y>=K:
    x,y=(x-K)%L,y-K
    
  Map[x][y]+=1
  Map[x][y-K]+=-1
  if x!=K:
    Map[x-K][y-K]+=1
    Map[x-K][y]+=-1
  if x>K:
    Map[0][y]+=1
    Map[0][y-K]+=-1

Map=[accumulate(i) for i in Map]
Map=[accumulate(i) for i in zip(*Map)]
Map=list(map(list,zip(*Map)))
Map=[map(add, Map[i][:K], Map[i-K][K:]) for i in range(L)]

print(max(map(max,Map)))