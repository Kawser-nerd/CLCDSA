L, N = [int(_) for _ in input().split()]
X = [int(input()) for _ in range(N)]


def calc(X):
    cumsum = [0]
    for x in X:
        cumsum += [cumsum[-1] + x]
    res = 0
    for i in range(N):
        if (i + N) % 2:
            end = (i + N - 1) // 2
            d = 2 * (cumsum[end + 1] - cumsum[i]) + 2 * L * (
                N - 1 - end) - 2 * (cumsum[N] - cumsum[end + 1]) - X[end]
        else:
            end = (i + N) // 2
            d = 2 * (cumsum[end] - cumsum[i]) + 2 * L * (N - end) - 2 * (
                cumsum[N] - cumsum[end]) - (L - X[end])
        res = max(res, d)
    return res


print(max(calc(X), calc([L - x for x in X[::-1]])))