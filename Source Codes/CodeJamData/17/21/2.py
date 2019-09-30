#!/usr/bin/env python3

TEST = 'large'
IN = 'A-{}.in'.format(TEST)
OUT = 'A-{}.out'.format(TEST)


def run(d, h):
    t = max((d - k) / s for k, s in h)
    return d / t


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            d, n = map(int, fin.readline().split())
            h = [tuple(map(int, fin.readline().split())) for i in range(n)]
            res = run(d, h)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
