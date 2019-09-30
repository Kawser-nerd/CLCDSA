#!/usr/bin/env python3

TEST = 'large'
IN = 'C-{}.in'.format(TEST)
OUT = 'C-{}.out'.format(TEST)


def run(n, h, d, q):
    for i in range(n):
        for j in range(n):
            if d[i][j] < 0:
                d[i][j] = None

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if d[i][k] is not None and d[k][j] is not None and (d[i][j] is None or d[i][j] > d[i][k] + d[k][j]):
                    d[i][j] = d[i][k] + d[k][j]

    e = [ei for ei, si in h]
    s = [si for ei, si in h]
    t = [
        [
            d[i][j] / s[i] if d[i][j] is not None and d[i][j] <= e[i] else None
            for j in range(n)
        ]
        for i in range(n)
    ]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if t[i][k] is not None and t[k][j] is not None and (t[i][j] is None or t[i][j] > t[i][k] + t[k][j]):
                    t[i][j] = t[i][k] + t[k][j]

    res = [t[u][v] for u, v in q]

    return ' '.join(map(str, res))


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            n, m = map(int, fin.readline().split())
            h = [tuple(map(int, fin.readline().split())) for i in range(n)]
            d = [list(map(int, fin.readline().split())) for i in range(n)]
            q = [tuple(x - 1 for x in map(int, fin.readline().split())) for i in range(m)]
            res = run(n, h, d, q)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
