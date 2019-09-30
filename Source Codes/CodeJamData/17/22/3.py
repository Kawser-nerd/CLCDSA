#!/usr/bin/env python3

TEST = 'large'
IN = 'B-{}.in'.format(TEST)
OUT = 'B-{}.out'.format(TEST)

IMP = 'IMPOSSIBLE'

def run(n, r, o, y, g, b, v):
    assert r + o + y + g + b + v == n

    if g > 0:
        if g > r:
            return IMP
        if g == r:
            if n > 2 * g:
                return IMP
            return 'GR' * g
        r -= g

    if v > 0:
        if v > y:
            return IMP
        if v == y:
            if n > 2 * v:
                return IMP
            return 'VY' * v
        y -= v

    if o > 0:
        if o > b:
            return IMP
        if o == b:
            if n > 2 * o:
                return IMP
            return 'OB' * o
        b -= o

    nn = r + y + b
    if max(r, y, b) > nn // 2:
        return IMP
    cols = [(r, 'R'), (y, 'Y'), (b, 'B')]
    cols.sort(reverse=True)
    s = ''.join(c * x for x, c in cols)
    if nn % 2 == 0:
        s1 = s[:nn//2]
        s2 = s[nn//2:]
        part = ''
    else:
        s1 = s[:nn//2]
        s2 = s[nn//2+1:]
        part = s[nn//2]
    s = ''.join(c1 + c2 for c1, c2 in zip(s1, s2)) + part

    if g > 0:
        s = s.replace('R', 'R' + 'GR' * g, 1)
    if v > 0:
        s = s.replace('Y', 'Y' + 'VY' * v, 1)
    if o > 0:
        s = s.replace('B', 'B' + 'OB' * o, 1)

    return s


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            n, r, o, y, g, b, v = map(int, fin.readline().split())
            res = run(n, r, o, y, g, b, v)
            print('Case #{}: {}'.format(i + 1, res), file=fout)


if __name__ == '__main__':
    main()
