N = int(input())
*A, = map(int, input().split())

MOD = 10**9 + 7

S = [0]*(N+1)
r = 0
for i in range(1, N+1):
    S[i] = r = (r + pow(i, MOD-2, MOD)) % MOD

ans = 0
for i in range(N):
    ans += A[i] * (S[i+1] + S[N-i] - 1)
for i in range(1, N+1):
    ans = ans * i % MOD
print(ans)