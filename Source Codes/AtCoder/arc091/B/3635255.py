N, K = map(int, input().split())
Ans = 0

if K == 0:
    print(N**2)
else:
    def Mods(i, N, K): #i???????K???N????
        lim = N//i
        pattern = i - K
        total = lim * pattern
        if N - i * lim < K:
            return total
        else:
            extra = N - i * lim - K + 1
            return total + extra

    for i in range(K+1, N+1):
        Ans += Mods(i, N, K)
    print(Ans)