N, C = [int(_) for _ in input().split()]
X = [0] * N
V = [0] * N
for i in range(N):
    X[i], V[i] = [int(_) for _ in input().split()]


def calc(X, V):
    Vcumsum = [0]
    for v in V:
        Vcumsum += [Vcumsum[-1] + v]
    cumsum = [0] * (N + 1)
    cumsum_r = [0] * (N + 1)
    for i in range(N):
        cumsum[i + 1] = Vcumsum[i + 1] - X[i]
        cumsum_r[i + 1] = Vcumsum[N] - Vcumsum[N - i - 1] - (C - X[-1 - i])
    cumsum_max = [0] * (N + 1)
    cumsum_r_max = [0] * (N + 1)
    for i in range(N):
        cumsum_max[i + 1] = max(cumsum[i + 1], cumsum_max[i])
        cumsum_r_max[i + 1] = max(cumsum_r[i + 1], cumsum_r_max[i])
    res = max(cumsum_max[-1], cumsum_r_max[-1])
    for i in range(N):
        res = max(
            res, cumsum_max[i + 1] + cumsum_r_max[N - i - 1] - X[i],
            cumsum_r_max[i + 1] + cumsum_max[N - i - 1] - (C - X[-1 - i]))
    return res


print(calc(X, V))