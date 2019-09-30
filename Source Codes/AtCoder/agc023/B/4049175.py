import numpy as np
n=int(input())
l=np.array([list(input()) for _ in range(n)])
ans=0

for _ in range(n):
    l=np.roll(l,1,axis=1)
    if (l==l.T).all():ans+=n

print(ans)