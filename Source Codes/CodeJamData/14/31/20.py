#!/usr/bin/env python

twos = {2 ** i: i for i in xrange(41)}

def readline():
    return map(int, raw_input().strip().split('/'))

def gcd(a, b):
    return gcd(b, a % b) if b != 0 else a

def solve():
    n, d = readline()
    g = gcd(n, d)
    n /= g
    d /= g
    if d not in twos:
        return 'impossible'
    i = 1
    while d > 0:
        if n >= d / 2:
            return i
        d /= 2
        i += 1
    return 'foobar'
    

def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
