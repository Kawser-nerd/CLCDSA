#!/usr/bin/env python

def readline():
    return map(int, raw_input().strip().split())

def solve():
    n, = readline()
    a = readline()
    m = {x: i for i, x in enumerate(sorted(a))}
    a = [m[x] for x in a]
    idx = {x: i for i, x in enumerate(a)}
    sw = 0
    for i in xrange(n):
        p = idx[i]
        l = sum(1 for x in a[:p] if x > i)
        r = n - 1 - i - l
        sw += min(l, r)
    return sw


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
