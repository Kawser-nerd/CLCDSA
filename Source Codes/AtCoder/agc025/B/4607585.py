n, A, B, k = list(map(int, input().split()))

MOD = 998244353
MAX = 3*10**5+2

fac = [0 for i in range(MAX)]
inv = [0 for i in range(MAX)]
ifac = [0 for i in range(MAX)]
fac[0] = 1; fac[1] = 1
inv[1] = 1
ifac[0] = 1; ifac[1] = 1

for i in range(2, MAX):
  fac[i] = fac[i-1]*i%MOD
  inv[i] = inv[MOD%i]*(MOD-MOD//i)%MOD
  ifac[i] = ifac[i-1]*inv[i]%MOD

def nCk(n, k):
  if n<k or n<0 or k<0: return 0
  return (((fac[n]*ifac[k])%MOD)*ifac[n-k])%MOD

ans = 0
for i in range(n+1):
  if (k-A*i)%B == 0:
    b = (k-A*i)//B
    if 0<=b<=n:
      ans = (ans+nCk(n, i)*nCk(n, b))%MOD

if ans==0:
  print(1)
else:
  print(ans)