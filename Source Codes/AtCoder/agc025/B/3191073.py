import sys
stdin = sys.stdin

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



MOD = 998244353

n,a,b,k = li()

# ???????
inv = inv_mod(n,MOD)
fac = fact(n,MOD)
facInv = fact_inv(n,inv,MOD)

ans = 0

for red in range(n+1):
    res = k - red*a
    if res%b != 0:
        continue
    else:
       blue = res//b
       
       ans = (ans + nCr(n,red,MOD,fac,facInv) * nCr(n,blue,MOD,fac,facInv)) % MOD

print(ans)