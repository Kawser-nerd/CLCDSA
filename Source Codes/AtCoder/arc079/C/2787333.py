import numpy as np
n=int(input())
a=np.array(list(map(int,input().split())))

res=0
f=np.vectorize(lambda x: x//n)
while True:
    b=f(a)
    s=b.sum()
    if s == 0:
        break
    else:
        res+=s
        a-=b*n
        a+=(s-b)

print(res)