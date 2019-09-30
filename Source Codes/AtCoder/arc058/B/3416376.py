H, W, A, B = map(int, input().split())
MOD = 10 ** 9 + 7
fact = [1]
for i in range(1, H + W + 1):
    fact.append((fact[-1] * i) % MOD)

u = {}
for i in range(B, W):
    t = fact[i + H - A - 1] * pow(fact[i] * fact[H - A - 1], MOD - 2, MOD)
    u[i + 1] = t % MOD

ans = 0
for k, v in u.items():
    t = fact[W - k + A - 1] * pow(fact[W - k] * fact[A - 1], MOD - 2, MOD) % MOD
    ans = (ans + t * v) % MOD

print(ans)