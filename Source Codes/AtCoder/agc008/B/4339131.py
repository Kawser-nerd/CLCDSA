import numpy as np
n,k=map(int, input().split())
a=np.array(list(map(int, input().split())))
b=np.maximum(a,0)
sm=sum(a[:k])
at=sum(b[k:])
ans=max(sm,0)+at
for i in range(k,n):
    sm+=a[i]-a[i-k]
    at+=b[i-k]-b[i]
    ans=max(max(0,sm)+at,ans)
print(ans)