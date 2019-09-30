N,A,B,K = map(int,input().split())
MOD = 998244353

if (A+B)*N < K:
    print(0)
    exit()

M = N+5
fac = [1,1] + [0]*M
finv = [1,1] + [0]*M
inv = [0,1] + [0]*M
for i in range(2,M+2):
    fac[i] = fac[i-1] * i % MOD
    inv[i] = -inv[MOD%i] * (MOD // i) % MOD
    finv[i] = finv[i-1] * inv[i] % MOD

def ncr(n,r):
    if n < r: return 0
    if n < 0 or r < 0: return 0
    return fac[n] * (finv[r] * finv[n-r] % MOD) % MOD

ans = 0
for a in range(N+1):
    rem = K - a*A
    if rem < 0: break
    b,m = divmod(rem, B)
    if m: continue
    ans += ncr(N,a) * ncr(N,b)
    ans %= MOD
print(ans)