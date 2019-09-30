from functools import reduce

# ??
N = int(input())
P = [int(input()) for _ in range(N)]

INF = 10**15

# P????
Q = {p: i for i, p in enumerate(P, 1)}

# j??????????????????????????????????
ans = reduce(
    lambda acc, j: (
        min(
            acc[0],
            acc[1] + N - j + 1
        ),
        acc[1] if j > N or Q[j - 1] < Q[j] else
        j - 1
    ),
    range(2, N + 2),
    (INF, 0)
)[0] if N >= 2 else 0

# ??
print(ans)