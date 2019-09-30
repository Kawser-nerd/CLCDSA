import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

# n???????
def inv_mod(n:int, mod:int) -> list:
    inv = [0,1]
    for i in range(2,n+1):
        inv.append(mod - ((mod//i)*inv[mod%i]) % mod)
    return inv
       
# n???????
def fact(n:int, mod:int) -> list:
    fac = [1,1]
    res = 1
    for i in range(2,n+1):
        res = res*i%mod
        fac.append(res)
    return fac

# n??????????
def fact_inv(n:int, inv:list, mod:int) -> list:
    facInv = [1,1]
    for i in range(2,n+1):
        facInv.append(facInv[i-1]*inv[i] % mod)
    return facInv
        
# ????
def nCr(n:int, r:int, mod:int, fac:list, facInv:list) -> int:
    if not (0<=r and r<=n):
        return 0
    
    return ((fac[n]*facInv[r]) % mod) * facInv[n-r] % mod

# nCr???????
def comb_sum(base: int, start: int, last: int, mod: int, fac: list, facInv:list):
    ret = 0
    for i in range(start, last+1):
        ret += nCr(base, i, mod, fac, facInv)
        
    return ret

n,a,b = li()
v = list(li())

v.sort(reverse=True)
maxv = max(v)
maxs = v.count(maxv)

MOD = 2**61-1
MAXN = 100
inv = inv_mod(MAXN, MOD)
fac = fact(MAXN, MOD)
fac_inv = fact_inv(MAXN, inv, MOD)


if maxs <= a:
    ans = sum(v[:a]) / a
    lastcnt = v.count(v[a-1])
    pat = nCr(lastcnt, a-v.index(v[a-1]), MOD, fac, fac_inv)
    
elif a < maxs < b:
    ans = maxv
    pat = comb_sum(maxs, a, maxs, MOD, fac, fac_inv)
    
else:
    ans = maxv
    pat = comb_sum(maxs, a, b, MOD, fac, fac_inv)
    
print(ans)
print(pat)