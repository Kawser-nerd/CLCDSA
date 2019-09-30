from bisect import bisect_left
def inpl(): return list(map(int, input().split()))

MOD = 10**9 + 7
N = int(input())
D = sorted([int(input()) for _ in range(N)])
S = [1]*(N)

for _ in range(3):
    DP = [0]*(N)
    for i in range(N):
        j = bisect_left(D, D[i]*2)
        if j != N:
            DP[j] = (DP[j] + S[i])%MOD

    S = [0]*(N)
    for i in range(1, N):
        S[i] = (DP[i] + S[i-1])%MOD

ans = 0
for i in range(N):
    ans = (ans + S[i])%MOD

print(ans)