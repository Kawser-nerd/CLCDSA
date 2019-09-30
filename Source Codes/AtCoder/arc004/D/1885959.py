def comb(n,k):
    ret = 1
    for i in range(k):
        ret *= n-i
        ret //= i+1
    return ret

mod = 10**9+7
n,m = map(int,input().split())
n = abs(n)

res = (2**m)//2%mod
for i in range(2,1000000):
    if i**2 > n: break
    if n%i==0:
        npow = 0
        while n%i==0:
            n //= i
            npow += 1
        res *= comb(npow+m-1,npow)
        res %= mod
if n > 1:
    res = res*m%mod
print(res)