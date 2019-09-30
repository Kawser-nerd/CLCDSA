N, K = map(int, input().split())
MOD = 10 ** 9 + 7


def prime(M):
    rec = []
    i = 2
    while i * i <= M:
        if M % i == 0:
            rec.append(i)
            while M % i == 0:
                M //= i
        i += 1
    if M > 1:
        rec.append(M)

    return rec


def calc(N, K):
    div = prime(K)
    Q = len(div)
    res = 0
    for i in range(1 << Q):
        mul = 1
        k = 0
        for j in range(Q):
            if i & 1 << j:
                mul *= div[j]
                k += 1

        d = N // mul
        tmp = d * (d + 1) // 2 * mul
        tmp %= MOD
        if k % 2 != 0:
            res -= tmp + MOD
            res %= MOD
        else:
            res += tmp
            res %= MOD

    return res


ans = 0
i = 1
while i * i <= K:
    if K % i == 0:
        ans += K * calc(N // i, K // i)
        ans %= MOD
        if K // i != i:
            ans += K * calc(N * i // K, i) % MOD
            ans %= MOD
    i += 1


print(ans)