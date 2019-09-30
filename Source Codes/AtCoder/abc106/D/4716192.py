import numpy as np
n,m,q=map(int,input().split())
a=np.zeros((n+2,n+2))
for i in range(m):
  s,e=map(int,input().split())
  a[s,e]+=1
#shift to left and add
b=a.cumsum(1)
#rotate 180
b=np.flipud(b)
#shift down and add
b=b.cumsum(0)
#rotate 180
b=np.flipud(b)

for i in range(q):
  s,e=map(int,input().split())
  print(int(b[s,e]))