def prime(N):
    p = 2
    koko = int(N**0.5)
    while N != 1:
        if N % p == 0:
            yaku[p] += 1
            N //= p
        elif p > koko:
            p = N
        else:
            p += 1
    return


N = int(input())

ans = 0
mod = 10**9 + 7
yaku = [0 for i in range(10**3)]
for i in range(1, N + 1):
    prime(i)

ans = 1
for a in yaku:
    ans *= a + 1
print(ans % mod)