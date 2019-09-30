#!/usr/bin/env python

def readline():
    return map(int, raw_input().strip().split())

def solve():
    c, d, v = readline()
    dd = readline()
    need = 0
    can = 0
    i = 0
    while can < v:
        if i < d and dd[i] <= can + 1:
            can += dd[i] * c
            i += 1
        else:
            need += 1
            can += (can + 1) * c
    return need


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
