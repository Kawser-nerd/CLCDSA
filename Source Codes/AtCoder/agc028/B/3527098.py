MOD = 10 ** 9 + 7


def mod_power(n, p, m):
    if p == 0: return 1
    if p % 2 == 0:
        half = mod_power(n, p // 2, m)
        return half * half % m
    else:
        return n * mod_power(n, p - 1, m)


n = int(input())
a = list(map(int, input().split()))

csum_invs = [0]
t = 0
for i in range(1, n + 1):
    t += mod_power(i, MOD - 2, MOD)
    t %= MOD
    csum_invs.append(t)

fact = []
t = 1
for i in range(1, n + 1):
    t *= i
    t %= MOD
    fact.append(t)

ans = 0
for i in range(n):
    coef = csum_invs[n - i]
    coef += csum_invs[i + 1]
    coef -= 1
    t = coef * a[i]
    t %= MOD
    ans += t

ans *= fact[-1]
ans %= MOD

print(ans)