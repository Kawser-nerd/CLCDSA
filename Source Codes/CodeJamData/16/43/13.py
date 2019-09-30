#!/usr/bin/env python3

TEST = 'small-attempt0'
IN = 'C-{}.in'.format(TEST)
OUT = 'C-{}.out'.format(TEST)


def cells(r, c):
    for i in range(r):
        for j in range(c):
            yield (i, j)


def construct(r, c, m):
    maze = [['-'] * c for i in range(r)]
    paths = {}
    for i, (rr, cc) in enumerate(cells(r, c)):
        if (m >> i) & 1:
            maze[rr][cc] = '/'
            paths[(rr-1, cc), (rr, cc)] = (rr, cc-1)
            paths[(rr+1, cc), (rr, cc)] = (rr, cc+1)
            paths[(rr, cc-1), (rr, cc)] = (rr-1, cc)
            paths[(rr, cc+1), (rr, cc)] = (rr+1, cc)
        else:
            maze[rr][cc] = '\\'
            paths[(rr-1, cc), (rr, cc)] = (rr, cc+1)
            paths[(rr+1, cc), (rr, cc)] = (rr, cc-1)
            paths[(rr, cc-1), (rr, cc)] = (rr+1, cc)
            paths[(rr, cc+1), (rr, cc)] = (rr-1, cc)
    return maze, paths


def side(r, c, i):
    if i < c:
        return (-1, i)
    i -= c
    if i < r:
        return (i, c)
    i -= r
    if i < c:
        return (r, c - 1 - i)
    i -= c
    if i < r:
        return (r - 1 - i, -1)
    assert False


def pairs(p):
    it = iter(p)
    while True:
        try:
            a = next(it)
            b = next(it)
        except StopIteration:
            break
        else:
            yield (a, b)


def follow(r, c, paths, s):
    if s[0] < 0:
        t = s[0] + 1, s[1]
    elif s[0] >= r:
        t = s[0] - 1, s[1]
    elif s[1] < 0:
        t = s[0], s[1] + 1
    elif s[1] >= c:
        t = s[0], s[1] - 1
    else:
        assert False
    while 0 <= t[0] < r and 0 <= t[1] < c:
        u = paths[s, t]
        s, t = t, u
    return t


def verify(r, c, paths, p):
    for a, b in pairs(p):
        ap = side(r, c, a)
        bp = side(r, c, b)
        if follow(r, c, paths, ap) != bp:
            return False
    return True


def run(r, c, p):
    for m in range(2 ** (r * c)):
        maze, paths = construct(r, c, m)
        if verify(r, c, paths, p):
            return '\n'.join(''.join(line) for line in maze)
    return 'IMPOSSIBLE'


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            r, c = map(int, fin.readline().split())
            p = [int(x) - 1 for x in fin.readline().split()]
            res = run(r, c, p)
            print('Case #{}:\n{}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
