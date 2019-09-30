def check_odd(i, j):
    return (i + j) % 2 == 0


def check_even(i, j):
    return i % 2 == 0


def solve(n, d1, d2):
    s1, s2 = 0, 0
    while d1 % 4 == 0:
        d1 >>= 2
        s1 += 1
    while d2 % 4 == 0:
        d2 >>= 2
        s2 += 1

    f1 = check_odd if d1 % 2 else check_even
    f2 = check_odd if d2 % 2 else check_even
    lim = n ** 2

    buf = []
    cnt = 0
    for i in range(2 * n):
        _i1 = i >> s1
        _i2 = i >> s2
        for j in range(2 * n):
            if f1(_i1, j >> s1) and f2(_i2, j >> s2):
                buf.append('{} {}'.format(i, j))
                cnt += 1
                if cnt == lim:
                    return buf


n, d1, d2 = map(int, input().split())
print('\n'.join(solve(n, d1, d2)))