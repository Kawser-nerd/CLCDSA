n,a,b,k=map(int,input().split())
mod=998244353
factorial=[1]
for i in range(1,n+1):
    factorial.append(factorial[i-1]*i%mod)
inverse=[0]*(n+1)
inverse[-1]=pow(factorial[-1],mod-2,mod)
for i in range(n-1,-1,-1):
    inverse[i]=inverse[i+1]*(i+1)%mod
def comb(n,r):
    if n<r:
        return 0
    return factorial[n]*inverse[r]*inverse[n-r]%mod
ans=0
for i in range(n+1):
    j=(k-a*i)//b
    if a*i+b*j==k and 0<=j<=n:
        ans+=comb(n,i)*comb(n,j)
        ans%=mod
print(ans)