N,K = map(int,input().split())

MOD = 10**9+7

def calc_divisors(n):
    ret = []
    m = 1
    while m*m <= n:
        if n%m == 0:
            ret.append(m)
            if m*m != n:
                ret.append(n//m)
        m += 1
    ret.sort()
    return ret

def calc_factors(n):
    ret = set()
    m = 2
    while m*m <= n:
        while n%m == 0:
            n //= m
            ret.add(m)
        m += 1
    if n > 1:
        ret.add(n)
    return ret

def sum_coprime(maxn,k):
    ret = 0
    factors = calc_factors(k)
    for b in range(1<<len(factors)):
        sign = 1
        mul = 1
        for i,f in enumerate(factors):
            if b&(1<<i):
                sign *= -1
                mul *= f
        ret += sign * mul * (maxn//mul) * (maxn//mul+1) //2
        ret %= MOD
    return ret

divisors = calc_divisors(K)
ans = 0
for d in divisors:
    ans += K * sum_coprime(N//d, K//d)
    ans %= MOD
print(ans)