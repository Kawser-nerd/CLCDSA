def inv(x, mod = 10 ** 9 + 7):
    return pow(x, mod - 2, mod)

mod = 10 ** 9 + 7
N = int(input())
fact = [1]
for i in range(1, N):
    fact.append(fact[-1] * i % mod)
inv_fact = [inv(fact[-1])]
for i in reversed(range(1, N)):
    inv_fact.append(inv_fact[-1] * i % mod)
inv_fact = inv_fact[::-1]

ans = prev = 0
for k in range((N + 1) // 2, N):
    cnt = fact[k - 1] * inv_fact[k * 2 - N] % mod * fact[k] % mod
    ans += (cnt - prev + mod) * k
    ans %= mod
    prev = cnt
print(ans)