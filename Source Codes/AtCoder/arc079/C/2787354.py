import numpy as np
n=int(input())
a=np.array(list(map(int,input().split())))
res,s=0,1
while s:
    b=a//n
    s=b.sum()
    res+=s
    a+=s-b*(n+1)
print(res)