from itertools import accumulate as ac
from math import pi
s=[0]*(2*(10**4)+1)
n,q=map(int,input().split())
for i in range(n):
    x,r,h=map(int,input().split())
    for j in range(x,x+h):
        p=x+h-j
        s[j+1]+=pi*(p*((r*p/h)**2)-(p-1)*((r*(p-1)/h)**2))/3
s=list(ac(s))
for i in range(q):
    a,b=map(int,input().split())
    print(s[b]-s[a])