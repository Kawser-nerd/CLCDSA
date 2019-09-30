from operator import mul
from functools import reduce

# ????????????????????
n,m = map(int,input().split())
MOD = 10**9+7

# ?????
def factorize(n):
    fct = [] # Prime Factor
    b, e = 2, 0
    while b*b <= n:
        while n % b == 0:
            n //= b
            e += 1
        if e > 0:
            fct.append((b,e))
        b, e = b+1, 0
    if n>1:
        fct.append((n,1))
    return fct

# ???????(nCr)
def nCr(n,r):
    r = min(r,n-r)
    if r == 0:
        return 1
    over = reduce(mul, range(n,n-r,-1))
    under = reduce(mul,range(1,r+1))
    return over // under

f = factorize(m)
ans=1
for p,num in f:
    ans *= nCr(num+n-1,num)
    ans %= MOD
    
print(ans)