# ??
x, y, W = [(int(x), int(y), W) for x, y, W in [input().split()]][0]
c = [input() for _ in range(9)]


# k: ??????????i: ?????j: ????
# di: ??????? dj: ??????
def f(k, i, j, di, dj):
    return (
        '' if k == 4 else
        c[i][j] + f(
            k + 1,
            i + di,
            j + dj,
            di if 0 < i + di < 8 else -di,
            dj if 0 < j + dj < 8 else -dj
        )
    )


# f????4??????
ans = f(
    0,
    y - 1,
    x - 1,
    (
        1 if ('D' in W and y - 1 < 8) or ('U' in W and y - 1 == 0) else
        -1 if ('U' in W and 0 < y - 1) or ('D' in W and y - 1 == 8) else
        0
    ),
    (
        1 if ('R' in W and x - 1 < 8) or ('L' in W and x - 1 == 0) else
        -1 if ('L' in W and 0 < x - 1) or ('R' in W and x - 1 == 8) else
        0
    )
)
# ??
print(ans)