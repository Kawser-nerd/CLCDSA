import math
from collections import defaultdict
x=defaultdict(int)
a,b=map(int,input().split())
d=10**9+7
l=1
for i in range(b+1,a+1):
    n=i
    for j in range(2,int(math.sqrt(i))+1):
        while n%j==0:
            x[j]+=1
            n=n//j
        if n<2:
            break
    else:
        if n!=1:
            x[n]+=1
for s in x.values():
    l=(l*(s+1))%d
print(l)