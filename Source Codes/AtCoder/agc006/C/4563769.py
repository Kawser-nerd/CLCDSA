from numpy import*
n,*a=map(int,open(0).read().split())
*s,=t=arange(n-1)
for i in a[-a[n]:]:t[[i-2,i-1]]=t[[i-1,i-2]]
k=a[n+1]
while k:s=[s,t[s]][k%2];t=t[t];k//=2
print(*cumsum(a[:1]+list(diff(a[:n])[s])))