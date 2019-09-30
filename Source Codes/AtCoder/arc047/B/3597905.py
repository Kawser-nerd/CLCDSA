from itertools import product as pd

n=int(input())
x,y=zip(*(tuple(map(int,input().split())) for _ in range(n)))
u,v=zip(*((i+j,i-j) for i,j in zip(x,y)))
d=max(max(u)-min(u),max(v)-min(v))

for i,j in pd((max(u)-d//2,min(u)+d//2),(max(v)-d//2,min(v)+d//2)):
  k,l=(i+j)//2,(i-j)//2
  s=set()
  for px,py in zip(x,y):
    s.add(abs(k-px)+abs(l-py))
    if len(s)>1:break
  else:
    print(k,l)
    break