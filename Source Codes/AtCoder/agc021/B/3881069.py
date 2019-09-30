import math;q=2*math.pi
from cmath import phase as h
t=lambda x:h(x)+(q if 0>h(x)else 0)
n=int(input())
r=range(n)
c=[complex(input().replace(' -', '-').replace(' ','+')+"j")for _ in r]
for i in r:a=sorted([t(c[j]-c[i])/q for j in r if j!=i]);d=[a[j]-a[j-1] for j in r[:-1]];d[0]+=1;print(max(max(d)-1/2,0))