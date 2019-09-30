N, K = map(int, input().split())
S = []; T = []
for x in range(1, int(N**.5)+1):
    if N % x == 0:
        S.append(x)
        if x*x < N:
            T.append(N//x)
T.reverse()
S += T
M = len(S)
U = []

MOD = 10**9 + 7
ans = 0
v = 0
for i in range(M):
    x = S[i]
    v = pow(K, (x+1)//2, MOD)
    for j in range(i):
        y = S[j]
        if x % y == 0:
            v -= U[j]
    U.append(v % MOD)
    ans = (ans + (v * x if x & 1 else v * (x//2))) % MOD
print(ans)