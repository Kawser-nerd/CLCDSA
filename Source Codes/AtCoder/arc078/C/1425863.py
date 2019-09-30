#!/usr/bin/env python3

def binsearch(l, r, pred): # [l, r)
    assert l < r
    l -= 1
    while r - l > 1:
        m = (l + r) // 2
        if pred(m):
            r = m
        else:
            l = m
    return r

import sys
def pred(n):
    assert 1 <= n and n <= 10 ** 18
    print('?', n)
    sys.stdout.flush()
    return input() == 'Y'

def solve():
    s = ''
    s += str(binsearch(1, 9 + 1, lambda c: not pred(int(s + str(c)))) - 1)

    if s == '9':
        f = lambda k: pred(int('1' + '0' * k))
    else:
        f = lambda k: not pred(int('9' * k))
    k = 1
    while f(k):
        k += 1
        if k >= 13:
            return 1

    if k == 1:
        return binsearch(1, 9 + 1, lambda c: pred(int(str(c) + '0')))
    else:
        for _ in range(k - 2):
            s += str(binsearch(0, 9 + 1, lambda c: not pred(int(s + str(c)))) - 1)
        s += str(binsearch(0, 9 + 1, lambda c: pred(int(s + str(c) + '0'))))

    return int(s)

print('!', solve())