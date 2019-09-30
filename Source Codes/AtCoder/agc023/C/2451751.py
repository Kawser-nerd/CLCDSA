n = int(input())
p = 10**9 + 7

def fact(n, p):
    n_ = [1]
    for i in range(1, n+1):
         n_.append((n_[-1]*i) % p)
    return n_

def invfact(n, f, p):
    m = [pow(f[n], p-2, p)]
    for i in range(n, 0, -1):
        m.append(m[-1] * i % p)
    return m

ans = 0
m = n - 1
f = fact(m, p)
rf = invfact(m, f, p)
rf.reverse()
perm = 0

for k in range((n+1)//2, n):
    perm_ = f[k-1] * rf[2*k-n] %p * f[k] % p
    ans += (perm_ - perm) %p * k % p
    ans %= p
    perm = perm_

print(ans)