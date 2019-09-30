mod=10**9+7
N=int(input())
a=[int(i) for i in input().split()]
F=1
for i in range(1,N+1):
  F=(F*i)%mod

def power(x,y):
  if y==0:
    return 1
  elif y==1:
    return x%mod
  elif y%2==0:
    return power(x,y//2)**2%mod
  else:
    return (power(x,y//2)**2)*x%mod
  
inv=[0]*(N)
for i in range(N):
  inv[i]=power(i+1,mod-2)
S_inv=[0]*(N+1)
for i in range(N):
  S_inv[i+1]=S_inv[i]+inv[i]
ans=0
for i in range(N):
  p=S_inv[i+1]+S_inv[N-i]-1
  ans=(ans+a[i]*F*p)%mod
print(ans)