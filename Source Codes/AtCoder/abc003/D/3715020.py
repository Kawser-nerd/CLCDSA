r, c = map(int, input().split())
x, y = map(int, input().split())
d, l = map(int, input().split())

mod = 10**9 + 7
fac = [1, 1]
inv = [1, 1]
finv = [1, 1]
for i in range(2, 1000):
    fac.append(fac[i-1] * i % mod)
    inv.append(mod - inv[mod%i] * (mod//i) % mod)
    finv.append(finv[i-1] * inv[i] % mod)

def nck(n, k):
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod

def nck_count(a, b):
    if a < 0 or b < 0 or d + l > a * b:
        return 0
    return (nck(a * b, d) * nck(a * b - d, l)) % mod

if d + l == x * y:
    num = nck(x*y, d) % mod
    num *= (r-x + 1) * (c-y + 1)
    num %= mod
    print(num)
else:
    num = nck_count(x, y)
    pie = nck_count(x-1, y) * 2 + nck_count(x, y-1) * 2
    pie -= nck_count(x-2, y) + nck_count(x, y-2) + nck_count(x-1, y-1) * 4
    pie += nck_count(x-2, y-1) * 2 + nck_count(x-1, y-2) * 2
    pie -= nck_count(x-2, y-2)
    pie %= mod
    ans = (((num - pie) % mod) * (r-x+1) * (c-y+1)) % mod
    print(ans)