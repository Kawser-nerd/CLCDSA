MOD = 10**9 + 7
N, A, B = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

if A == 1:
    for x in a:
        print(x % MOD)
else:
    while B > 0 and max(a) >= a[0]*A:
        a[0] *= A
        a.sort()
        B -= 1
    powers = [B//N] * N
    for i in range(B%N):
        powers[i] += 1
    for i in range(B%N, N):
        x,p = a[i], powers[i]
        print((x * pow(A, p, MOD)) % MOD)
    for i in range(0, B%N):
        x,p = a[i], powers[i]
        print((x * pow(A, p, MOD)) % MOD)