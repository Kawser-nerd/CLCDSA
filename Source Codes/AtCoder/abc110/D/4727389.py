MOD = 10**9+7
# ?????????????????O(1)???
MAX = 10**6
fac = [0]*MAX  # fac[n]:  (n!) mod p
finv = [0]*MAX # finv[n]: (n!)^-1 mod p
inv = [0]*MAX  # inv[n]:  (n)^-1 mod p

def comb_init():
    global fac, finv, inv
    fac[0] = fac[1] = 1
    finv[0] = finv[1] = 1
    inv[1] = 1
    for i in range(2, MAX):
        fac[i] = fac[i-1] * i % MOD
        inv[i] = MOD - inv[MOD%i] * (MOD//i)%MOD
        finv[i] = finv[i-1] * inv[i] % MOD

def comb(n:int, r:int)->int:
    global fac, finv
    if n < r: return 0
    if n < 0 or r < 0: return 0
    return fac[n] * (finv[r] * finv[n-r] % MOD) % MOD

if __name__ == '__main__':
    N,M = map(int, input().split())
    ans = 1
    comb_init()
    
    #  ?????
    i=2
    nokori = M
    while i*i <= nokori:
        if nokori%i==0:
            cnt = 0
            while nokori%i==0:
                cnt += 1
                nokori //= i
            ans *= comb(N+cnt-1, N-1)
            ans %= MOD
        i += 1
            
    if nokori != 1:
        ans *= comb(N+1-1, N-1)
        ans %= MOD
        
    print(ans)