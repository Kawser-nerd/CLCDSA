N,M = map(int,input().split())
src = [int(input()) for i in range(N)]

used = [0] * (M+1)
rtol = [None] * N
ans = 0
r = 0
for l in range(N):
    while r < N and not used[src[r]]:
        used[src[r]] += 1
        rtol[r] = l
        r += 1
    used[src[l]] -= 1

MOD = 10**9+7
dp = [1]
cdp = [0,1]
for r in range(N):
    l = rtol[r]
    dp.append(cdp[-1] - cdp[l])
    cdp.append((cdp[-1] + dp[-1])%MOD)
print(dp[-1] % MOD)