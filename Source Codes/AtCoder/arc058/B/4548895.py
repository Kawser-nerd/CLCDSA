H, W, A, B = map(int, input().split())
MAX = H + W
MOD = 10 ** 9 + 7
fac = [0 for _ in range(MAX)]
finv = [0 for _ in range(MAX)]
inv = [0 for _ in range(MAX)]
fac[0] = fac[1] = 1
finv[0] = finv[1] = 1
inv[1] = 1
for i in range(2, MAX):
    fac[i] = fac[i - 1] * i % MOD
    inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
    finv[i] = finv[i - 1] * inv[i] % MOD


def COM(n, k):
    global fac
    global finv
    global MOD
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD


def route(h, w):
    return COM(h + w - 2, h - 1)


ans = 0
for w in range(B + 1, W + 1):
    ans += route(H - A, w) * route(A, W - w + 1)
    ans %= MOD
print(ans % MOD)