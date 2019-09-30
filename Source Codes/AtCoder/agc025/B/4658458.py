n,a,b,k=map(int,input().split())
p=998244353
def getinv(n):
  inv=[0]*(n+1)
  inv[1]=1
  for i in range(2,n+1):
    inv[i]=(-(p//i)*inv[p%i])%p
  return inv
def getnCr(n):
  inv=getinv(n)
  nCr=[0]*(n+1)
  nCr[0]=1
  for i in range(1,n+1):
    nCr[i]=(nCr[i-1]*(n-i+1)*inv[i])%p
  return nCr
def solve(n,a,b,k):
  ans=0
  nCr=getnCr(n)
  for i in range(n+1):
    if (k-a*i)<0 or (k-a*i)%b!=0:
      continue
    j=(k-a*i)//b
    if a*i+b*j==k and 0<=j<=n:
      ans+= nCr[i]*nCr[j]
      ans%=p
  return ans
print(solve(n,a,b,k))