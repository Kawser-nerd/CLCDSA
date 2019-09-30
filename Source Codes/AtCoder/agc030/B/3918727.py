L, N = map(int, input().split())
X = []
for i in range(N):
    X.append(int(input()))

X = sorted(X)

ma = 0
for k in range(2):
    if k == 1:
        X = [L-X[-i] for i in range(1, N+1)]
    s = X[0]
    for i in range(1, N):
        if i % 2 == 1:
            s += L - X[-(i//2)-1] + X[i//2]
        else:
            s += X[i//2] + (L - X[-(i//2)])

    ma = max(ma, s)
    lt = (N-1) // 2 if N % 2 == 1 else -N//2
    for i in range(1, N):
        if lt > 0:
            if N % 2 == 1:
                s += X[lt] - X[i-1]*2 - (L - X[lt + 1])
            else:
                s += X[lt] - X[i-1] * 2 - (L - X[lt + 1])
            lt = 1 + lt - N
            ma = max(ma, s)
        else:
            if N % 2 == 1:
                s += X[lt] - X[i-1] * 2 - (L - X[lt])
            else:
                s += X[lt]*2 - L - X[i-1] * 2
            lt = N + lt
            ma = max(ma, s)

print(ma)