def ARC067():
    N, A, B = map(int, input().split())
    X = list(map(int, input().split()))
    if A >= B:
        A = B
    ans = 0
    for i in range(1, N):
        if (X[i] - X[i - 1]) * A > B:
            ans += B
        else:
            ans += A * (X[i] - X[i - 1])
    print(ans)
ARC067()