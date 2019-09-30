w, h = map(int, input().split())

MOD = 10 ** 9 + 7

n = w + h - 2
r = min(w-1, h-1)

ans = 1
for i in range(r):
    ans = (ans * (n-i)) % MOD

div = 1
inv = [0] * (r+1)
inv[1] = 1
for i in range(2, r+1):
    inv[i] = (-(MOD // i) * inv[MOD%i]) % MOD
    div = (div * inv[i]) % MOD

print((ans * div) % MOD)