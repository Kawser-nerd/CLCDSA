N, M = map(int, input().split(' '))
MOD = 10**9 + 7
if abs(N-M) > 1:
    print(0)
    exit()

ans = 1
for i in range(N):
    ans = ans * (i+1) % MOD
for i in range(M):
    ans = ans * (i+1) % MOD
if N == M:
    ans = ans * 2 % MOD
print(ans)