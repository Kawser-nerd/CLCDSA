def solve(n, m, a, b):
    cell = n * m
    need = 2 * (a + b)
    if cell < need:
        return 'NO'

    d = '.<>^v'
    f = [[0] * m for _ in range(n)]

    if n & 1:
        for j in range(0, m - 1, 2):
            if a:
                f[-1][j] = 1
                f[-1][j + 1] = 2
                a -= 1
            else:
                break
    if m & 1:
        for i in range(0, n - 1, 2):
            if b:
                f[i][-1] = 3
                f[i + 1][-1] = 4
                b -= 1
            else:
                break

    sqa = a // 2
    sqb = b // 2
    sq = sqa + sqb
    ra, rb = a & 1, b & 1
    sqc = (n // 2) * (m // 2)
    if sq > sqc:
        return 'NO'
    if sq == sqc and (ra or rb):
        return 'NO'
    if sq + 1 == sqc and (ra and rb):
        if n & 1 and m & 1:
            f[-3][-3] = f[-1][-2] = 1
            f[-3][-2] = f[-1][-1] = 2
            f[-3][-1] = f[-2][-3] = 3
            f[-2][-1] = f[-1][-3] = 4
            ra = rb = 0
        else:
            return 'NO'

    i, j = 0, 0
    for i in range(0, n - 1, 2):
        for j in range(0, m - 1, 2):
            if sqa:
                f[i][j] = f[i + 1][j] = 1
                f[i][j + 1] = f[i + 1][j + 1] = 2
                sqa -= 1
            elif sqb:
                f[i][j] = f[i][j + 1] = 3
                f[i + 1][j] = f[i + 1][j + 1] = 4
                sqb -= 1
            else:
                break
            # print(sqa, sqb)
            # print('\n'.join(''.join(map(d.__getitem__, r)) for r in f))
            # print('---')
        else:
            continue
        break
    if ra:
        f[i][j] = 1
        f[i][j + 1] = 2
        j += 2
        if j >= m - 1:
            j = 0
            i += 2
    if rb:
        f[i][j] = 3
        f[i + 1][j] = 4

    return 'YES\n' + '\n'.join(''.join(map(d.__getitem__, r)) for r in f)


n, m, a, b = map(int, input().split())
print(solve(n, m, a, b))