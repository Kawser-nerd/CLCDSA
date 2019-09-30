N, M = map(int, input().split())

mod = 10**9+7 #?????
P = 10**5
g1 = [1, 1] # ????? ??

for i in range( 2, P + 1 ):
    g1.append( ( g1[-1] * i ) % mod )

if abs(N - M) == 0:
    print(g1[N] * g1[M] * 2 % mod)
elif abs(N - M) == 1:
    print(g1[N] * g1[M] % mod)
else:
    print(0)