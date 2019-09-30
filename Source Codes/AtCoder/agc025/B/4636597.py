n, a, b, k = map(int, input().split())

mod = 998244353

# combination---
# n?mod??????

fac = [1, 1]
inv = [1, 1]
finv = [1, 1]
for i in range(2, n+5):
    fac.append(fac[i-1] * i % mod)
    inv.append(mod - inv[mod%i] * (mod//i) % mod)
    finv.append(finv[i-1] * inv[i] % mod)

def nck(n, k):
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod

ans = 0
for ca in range(n+1):
    cb = (k - a * ca) // b
    if (k - a * ca) % b != 0:
        continue
    ans += nck(n, ca) * nck(n, cb)
    ans %= mod

print(ans)