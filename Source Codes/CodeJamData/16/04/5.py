#!/usr/bin/env python3

TEST = 'large'
IN = 'D-{}.in'.format(TEST)
OUT = 'D-{}.out'.format(TEST)


def run(k, c, s):
    digs = []
    for i in range(k):
        if not digs or len(digs[-1]) == c:
            digs.append([])
        digs[-1].append(i)
    if len(digs) > s:
        return 'IMPOSSIBLE'

    def conv(dig):
        r = 0
        for x in dig:
            r = r * k + x
        return r + 1

    return ' '.join(map(str, map(conv, digs)))


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            k, c, s = map(int, fin.readline().strip().split())
            res = run(k, c, s)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
