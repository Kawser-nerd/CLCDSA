n,a,b,k=map(int,input().split())
m=998244353
I=[0]*n
for i in range(n):
  I[i]=pow(i+1,m-2,m)
c=[0]*(n+1)
c[0]=1
for i in range(1,n+1):
  c[i]=(c[i-1]*(n-i+1)*I[i-1])%m
q=0
for i in range(n+1):
  j=(k-i*a)//b
  if (k-i*a)%b or j<0 or j>n:continue
  q=(q+c[i]*c[j])%m 
print(q%m)