#!/usr/bin/env python

def readline():
    return map(int, raw_input().strip().split())

def solve():
    n, x = readline()
    s = readline()
    s.sort()
    a, b = 0, n
    cd = 0
    while a < b:
        b -= 1
        cd += 1
        r = x - s[b]
        if a < b and s[a] <= r:
            a += 1
    return cd


def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
