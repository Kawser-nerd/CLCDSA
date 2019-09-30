N, K = map(int, input().split())
# Mod = 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
Mod = 1000000007


def list_prime_divisor(k):
    res = []
    i = 2
    while i * i <= k:
        if i * i > k:
            break
        if k % i == 0:
            res.append(i)
            while k % i == 0:
                k //= i
        i += 1

    if k != 1:
        res.append(k)
    return res


def sum_gcd_one(n, k):
    d = list_prime_divisor(k)
    # print(k,d)
    plus = 0
    minus = 0
    for i in range(1 << len(d)):
        cpi = i
        ll = 1
        cnt = 0
        for j in d:
            if cpi % 2 == 1:
                cnt += 1
                ll *= j
            cpi //= 2

        if cnt % 2 == 0:
            plus += s(n // ll) * ll
            plus %= Mod
        else:
            minus += s(n // ll) * ll
            minus %= Mod

    plus += (Mod - minus)
    plus %= Mod
    return plus


def s(n):
    return (((n + 1) * n) // 2) % Mod


# print(KPrimeDivisor)
ans = 0
div = []
i1 = 1
while i1 * i1 <= K:
    if K % i1 == 0:
        div.append(i1)
        if K // i1 != i1:
            i2 = K // i1
            div.append(i2)
    i1 += 1

div.sort()
#print(div)
for i3 in div:
    ans += K * sum_gcd_one(N // i3, K // i3) % Mod
ans %= Mod
print(ans)