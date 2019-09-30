N = int(input())
for num in range(1, N + 1):
    X, S, R, T, n = map(int,input().split())
    L = {}
    W = {}
    L[0] = X
    W[0] = 0
    for i in range(1, n + 1):
        b, e, w = map(int,input().split())
        L[i] = (e - b)
        W[i] = w
        L[0] -= (e - b)
    Idx = list(range(n + 1))
    Idx = sorted(Idx, key = W.get)
    Answer = 0
    for i in Idx:
        if T == 0:
            Answer += L[i] / (W[i] + S)
        elif (W[i] + R) * T >= L[i]:
            Answer += L[i] / (W[i] + R)
            T -= L[i] / (W[i] + R)
        else:
            Answer += T + (L[i] - T * (W[i] + R)) / (W[i] + S)
            T = 0

    print("Case #", num, ": ", Answer, sep = '')

