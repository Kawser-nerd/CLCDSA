n = int(input())
p = 10**9 + 7

def fact(n):
    n_ = 1
    yield n_
    for i in range(1, n+1):
         n_ = (n_*i) % p
         yield n_

def invfact(n, f, p):
    m = pow(f[n], p-2, p)
    yield m
    for i in range(n, 0, -1):
        m = m * i % p
        yield m

ans = 0
m = n - 1
f = list(fact(m))
rf = list(invfact(m, f, p))
rf.reverse()
perm = 0

for k in range((n+1)//2, n):
    perm_ = f[k-1] * rf[2*k-n] %p * f[k] % p
    ans += (perm_ - perm) %p * k % p
    ans %= p
    perm = perm_

print(ans)