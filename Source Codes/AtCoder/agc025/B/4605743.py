def cmb(n,r,mod):
  if r<0 or r>n:
    return 0
  r=min(r,n-r)
  return g1[n]*g2[r]*g2[n-r]%mod

n,a,b,k=map(int,input().split())
m=998244353
count=0

g1=[1,1]
g2=[1,1]
inverse=[0,1]

for i in range(2,n+1):
  g1.append((g1[-1]*i)%m)
  inverse.append((-inverse[m%i]*(m//i))%m)
  g2.append((g2[-1]*inverse[-1])%m)

for j1 in range(n+1):
  if (k-a*j1)%b==0:
    j2=(k-a*j1)//b
    count+=cmb(n,j1,m)*cmb(n,j2,m)
  count%=m
print(count)