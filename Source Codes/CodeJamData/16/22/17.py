#!/usr/bin/env python3

from collections import Counter

TEST = 'large'
IN = 'B-{}.in'.format(TEST)
OUT = 'B-{}.out'.format(TEST)


def min_opt(x):
    return x.replace('?', '0')

def max_opt(x):
    return x.replace('?', '9')


def opt(c, j):
    return abs(int(c) - int(j)), c, j

def options(c, j, pref=''):
    if not c:
        yield opt(pref, pref)
        return
    ci, ji = c[0], j[0]
    if ci != '?' and ji != '?':
        if ci < ji:
            yield opt(pref + max_opt(c), pref + min_opt(j))
        elif ci > ji:
            yield opt(pref + min_opt(c), pref + max_opt(j))
        else:
            yield from options(c[1:], j[1:], pref + ci)
    elif ci != '?':
        if ci != '0':
            yield opt(pref + min_opt(c), pref + str(int(ci) - 1) + max_opt(j[1:]))
        if ci != '9':
            yield opt(pref + max_opt(c), pref + str(int(ci) + 1) + min_opt(j[1:]))
        yield from options(c[1:], j[1:], pref + ci)
    elif ji != '?':
        if ji != '0':
            yield opt(pref + str(int(ji) - 1) + max_opt(c[1:]), pref + min_opt(j))
        if ji != '9':
            yield opt(pref + str(int(ji) + 1) + min_opt(c[1:]), pref + max_opt(j))
        yield from options(c[1:], j[1:], pref + ji)
    else:
        yield opt(pref + '0' + max_opt(c[1:]), pref + '1' + min_opt(j[1:]))
        yield opt(pref + '1' + min_opt(c[1:]), pref + '0' + max_opt(j[1:]))
        yield from options(c[1:], j[1:], pref + '0')


def run(c, j):
    diff, rc, rj = min(options(c, j))
    return ' '.join([rc, rj])


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            c, j = fin.readline().strip().split()
            res = run(c, j)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
