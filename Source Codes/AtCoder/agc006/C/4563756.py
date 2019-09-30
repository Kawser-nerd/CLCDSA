from numpy import*
n,*a=map(int,open(0).read().split())
t=arange(n-1)
*s,=t
for i in a[-a[n]:]:t[i-2],t[i-1]=t[i-1],t[i-2]
k=a[n+1]
while k:
    if k%2:s=t[s]
    t=t[t]
    k//=2
print(*cumsum(a[:1]+list(diff(a[:n])[s])))