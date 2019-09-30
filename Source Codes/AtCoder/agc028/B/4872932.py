N = int(input())
a = list(map(int, input().split()))

MOD = 10 ** 9 + 7
M = 100005
fact = [0] * M
fact[0] = 1
for i in range(1, M):
    fact[i] = fact[i - 1] * i
    fact[i] %= MOD

inv = [0] * M
inv[1] = 1
for i in range(2, M):
    inv[i] = inv[i - 1] + pow(i, MOD - 2, MOD)
    inv[i] %= MOD

ans = 0
for i in range(1, N + 1):
    ans += (inv[i] + inv[N - i + 1] - 1 + MOD) * a[i - 1] % MOD
    ans %= MOD

print((ans * fact[N]) % MOD)