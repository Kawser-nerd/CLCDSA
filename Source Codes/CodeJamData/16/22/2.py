#!/usr/bin/env python3

def result ( a, b ):
    global ans
    x = ''.join (a)
    y = ''.join (b)
    res = (abs (int (x) - int (y)), x, y)
    if ans is None or res < ans:
        ans = res

def solve ( a, b, i = 0, mn = 0 ):
    # print ("solve (a=%s, b=%s, i=%d, mn=%d)" % (repr (a), repr (b), i, mn))
    if i == len (a):
        result (a, b)
        return
    for xa in range (0, 9 + 1):
        for xb in range (0, 9 + 1):
            if xb < 0 or xb > 9:
                continue
            ca = chr (xa + ord ('0'))
            cb = chr (xb + ord ('0'))
            # print ("  x = %d,%d" % (xa, xb))
            if a[i] != ca and a[i] != '?':
                continue
            if b[i] != cb and b[i] != '?':
                continue
            if a[i] == '?' and mn == 1 and ca != '0':
                continue
            if a[i] == '?' and mn == 2 and ca != '9':
                continue
            if b[i] == '?' and mn == 2 and cb != '0':
                continue
            if b[i] == '?' and mn == 1 and cb != '9':
                continue
            if a[i] == '?' and b[i] == '?' and ca == cb and mn == 0 and xa != 0:
               continue
            ra, rb = a[i], b[i]
            a[i] = ca
            b[i] = cb
            nmn = mn
            if mn == 0 and ca > cb:
                nmn = 1
            if mn == 0 and ca < cb:
                nmn = 2
            solve (a, b, i + 1, nmn)
            a[i] = ra
            b[i] = rb

tn = int (input ())
for t in range (1, tn + 1):
    a, b = input ().split ()
    a = [x for x in a]
    b = [x for x in b]
    assert len (a) == len (b)
    ans = None
    solve (a, b)
    res, x, y = ans
    print ("Case #%d: %s %s" % (t, ''.join (x), ''.join (y)))

