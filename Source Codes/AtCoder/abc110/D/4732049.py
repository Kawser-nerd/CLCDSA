from collections import Counter
from scipy.misc import comb
c=Counter()
n,m=map(int,input().split())
t=2
#Fanction of Factoring
while(t**2 <= m):
    if m%t:
        t+=1
        continue
    while m%t==0:
        c[t]+=1
        m//=t
if m>1:c[m]+=1
a=1

for i in c:
    a=a*comb(n+c[i]-1,n-1,exact=1)%(10**9+7)
print(a)