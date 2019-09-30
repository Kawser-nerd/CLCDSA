import math
def soinsu(N):
    sqr = int(math.sqrt(N))
    lis = []
    for i in range(2,sqr+2):
        while N % i == 0:
            lis.append(i)
            N = N // i
    if not N == 1:
        lis.append(N)
    return lis
mod = 1000000007
def modpow(a,b,MOD=mod):
    res = 1
    while b > 0:
        if (b & 1) == 1:
            res = (res*a) % MOD
        a = (a*a) % MOD
        b = b >> 1
    return res
fact = []
def ncrinit(MOD=mod):
    fact.append(1)
    for i in range(1,110005):
        fact.append((fact[i-1]*i)%MOD)

def calcnCr(n,r,MOD=mod):
    up = fact[n]
    down = modpow((fact[n-r]*fact[r])%mod,mod-2,mod)
    return (up*down)%mod

def compres(lis):
    li = []
    se = set(lis)
    for i in se:
        li.append(lis.count(i))
    return li
res = 1
N,M = list(map(int,input().split()))
ncrinit()
co = compres(soinsu(M))
for i in co:
    res = (res* (calcnCr(i+N-1,i)))%mod
print(res)