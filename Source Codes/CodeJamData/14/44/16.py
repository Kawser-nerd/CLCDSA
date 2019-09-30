#!/usr/bin/env python

MOD = 10 ** 9 + 7

def readline():
    return map(int, raw_input().strip().split())

def pre(a, b):
    s = 0
    z = min(len(a), len(b))
    while s < z and a[s] == b[s]:
        s += 1
    return s

def solve():
    m, n = readline()
    s = [raw_input().strip() for i in xrange(m)]
    r = [0, 0]
    def test(b):
        if not all(b):
            return
        nn = 0
        for s in b:
            nn += 1
            s.sort()
            last = ''
            for w in s:
                nn += len(w) - pre(w, last)
                last = w
        if nn > r[0]:
            r[0] = nn
            r[1] = 1
        elif nn == r[0]:
            r[1] += 1
    def rec(s, b):
        if not s:
            test(b)
            return
        for i in xrange(len(b)):
            bb = b[:]
            bb[i] = bb[i] + [s[0]]
            rec(s[1:], bb)
    rec(s, [[] for i in xrange(n)])
    return '{} {}'.format(r[0], r[1] % MOD)


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
