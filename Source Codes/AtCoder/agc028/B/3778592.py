from math import factorial

MOD = 10 ** 9 + 7

N = int(input())
A = list(map(int, input().split()))

invsum = [0] * (N + 1)
for i in range(1, N + 1):
    invsum[i] = (invsum[i - 1] + pow(i, MOD - 2, MOD)) % MOD

ans = 0
for i in range(1, N + 1):
    ans += (A[i - 1] * (invsum[i] + invsum[N - i + 1] - 1)) % MOD

ans *= factorial(N)
print(ans % MOD)