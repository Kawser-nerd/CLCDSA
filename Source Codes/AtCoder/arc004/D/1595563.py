from collections import defaultdict
N,M = map(int, input().split())
AN = abs(N)
MOD = 10**9+7

factors = defaultdict(lambda: 0)
p = 2
n = AN
while p*p <= AN:
    while n%p == 0:
        n //= p
        factors[p] += 1
    p += 1
if n != 1:
    factors[n] += 1

def mul(a,b):
    return (a * b) % MOD

def pow(a,n): # a^n
    ret = 1
    mag = a
    while n > 0:
        if n & 1:
            ret = mul(ret, mag)
        mag = mul(mag, mag)
        n >>= 1
    return ret

def inv(a):
    return pow(a,MOD-2)

fac = [1]
fac_inv = [1]
for n in range(1,M+100):
    f = mul(fac[n-1], n)
    fac.append(f)
    fac_inv.append(inv(f))

def ncr(n,r):
    return mul(mul(fac[n], fac_inv[n-r]), fac_inv[r])

def nhr(n,r):
    a = ncr(n+r-1, r)
    return ncr(n+r-1, r)

ans = 1
for n in factors.values():
    ans = mul(ans, nhr(M,n))
ans = mul(ans, pow(2,M-1))
print(ans)