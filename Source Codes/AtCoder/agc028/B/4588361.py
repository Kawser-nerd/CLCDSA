from math import factorial

MOD = 10**9 + 7

N = int(input())
As = list(map(int, input().split()))

invs = [1] * (N+1)
for x in range(2, N+1):
    invs[x] = (-(MOD//x) * invs[MOD%x]) % MOD

accInvs = [0] * (N+1)
for i, inv in enumerate(invs[1:], 1):
    accInvs[i] = (accInvs[i-1] + inv) % MOD

ans = 0
for i, A in enumerate(As):
    coef = (accInvs[i+1] + accInvs[N-i] - 1) % MOD
    ans += coef * A
    ans %= MOD

factN = factorial(N) % MOD
print(ans*factN % MOD)