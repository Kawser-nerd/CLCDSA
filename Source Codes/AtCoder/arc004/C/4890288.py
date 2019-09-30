from math import ceil

# ??
X, Y = map(int, input().split('/'))

# N ???
N = (
    (2 * X // Y, 2 * X // Y + 1) if 2 * X % Y == 0 else
    (ceil(2 * X / Y) - 1, ceil(2 * X / Y))
)
# M ???
M = [
    n * (n + 1) // 2 - n * X // Y if n * X % Y == 0 else
    0
    for n in N
]
# ??????N, M?????
ans = (
    'Impossible' if all(
        m <= 0 or m > n
        for n, m in zip(N, M)
    ) else
    '\n'.join(
        '{} {}'.format(n, m)
        for n, m in zip(N, M)
        if 1 <= m <= n
    )
)

# ??
print(ans)