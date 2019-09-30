#!/usr/bin/env python3

import sys

def divisor ( x ):
    d = 2
    while d <= 1000 and d * d <= x:
        if x % d == 0:
            return d
        d += 1
    return 0


def main ():
    tn = int (input ())
    assert tn == 1
    n, j = map (int, input ().split ())

    ans = []
    x = (1 << (n - 1)) + 1
    while len (ans) < j:
        ok = True
        divs = []
        print ("check: %d" % x, file=sys.stderr)
        for base in range (2, 11):
            value = 0
            for i in range (n - 1, -1, -1):
                value = value * base + (x >> i) % 2;
            divs.append (divisor (value))
            if not divs[-1]:
                ok = False
                break
        if ok:
            ans.append ((x, divs))
        x += 2

    print ("Case #1:")
    for value, divs in ans:
        binary = ""
        while value > 0:
            binary = ("%d" % (value % 2)) + binary
            value //= 2
        print ("%s %s" % (binary, ' '.join (map (str, divs))))

main ()

