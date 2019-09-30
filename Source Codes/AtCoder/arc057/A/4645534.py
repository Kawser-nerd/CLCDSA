A, K = map(int, input().split())
N = 2*10**12
Res = 0

if K != 0:
    while A < N:
        Res += 1
        A += 1 + K*A
else:
    Res = N - A

print(Res)