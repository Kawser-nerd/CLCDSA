import sys,math

mod = 10 ** 9 + 7

def fact(a):
    ret = [1] * (a+1)
    for i in range(2,a+1):
        ret[i] = (ret[i-1]*i) % mod
    return ret

def inverse_fact(a):
    ret = [1] * (a + 1)
    fac = fact(a)
    ret[a] = power(fac[a], mod-2)
    for i in reversed(range(2, a)):
        ret[i] = (ret[i + 1] * (i + 1)) % mod
    return ret

def power(x, y):
    if y == 0: 
        return 1
    elif y % 2 == 0: 
        return power(x**2%mod, y//2) % mod
    else: 
        return (power(x**2%mod, (y-1)//2) * x) % mod
        
def comb(n, r, fac, inv):
    return (fac[n] * inv[r] * inv[n - r]) % mod
    
def combination(n, r, P, fac, inv):
    return (fac[n] * inv[r] * inv[n - r]) % P
    
def solve():
    H,W,A,B = map(int,input().split())
    move_count = H+W
    fac = fact(move_count)
    inv = inverse_fact(move_count)
    ans = 0
    for i in range(A):
        ans = (ans + comb((H-1-i)+(B-1), B-1, fac, inv) * comb(i+(W-1-B), i, fac, inv)) % mod
    print((comb((H - 1) + (W - 1), H - 1, fac, inv) - ans) % mod)
    
solve()