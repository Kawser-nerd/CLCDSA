def inpl(): return [int(i) for i in input().split()]
N, M = inpl()
mod = 10**9+7
fac = [1 for _ in range(N+3)]
for i in range(N+2):
    fac[i+1] = (i+1)*fac[i]%mod

if abs(N-M) > 1:
    print(0)
elif N == M:
    print(2*fac[N]*fac[M]%mod)
else:
    print(fac[N]*fac[M]%mod)