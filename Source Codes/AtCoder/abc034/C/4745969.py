W,H = map(int,input().split())
MOD = 10**9+7

N = W+H+10
fac = [1,1] + [0]*N
finv = [1,1] + [0]*N
inv = [0,1] + [0]*N
for i in range(2,N+2):
    fac[i] = fac[i-1] * i % MOD
    inv[i] = -inv[MOD%i] * (MOD // i) % MOD
    finv[i] = finv[i-1] * inv[i] % MOD

def ncr(n,r):
    if n < r: return 0
    if n < 0 or r < 0: return 0
    return fac[n] * (finv[r] * finv[n-r] % MOD) % MOD
def nhr(n,r):
    return ncr(n+r-1, r)

print(ncr(H+W-2, H-1))