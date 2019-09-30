#!/usr/bin/env python

import decimal
import sys

d = decimal.Decimal
decimal.getcontext().prec = 1000
base = d('3') + d('5').sqrt()

n = int(sys.stdin.readline())
for case in xrange(1, n+1):
    p = int(sys.stdin.readline())
    x = base ** p
    s = '000' + str(x)
    s = s[:s.find('.')]
    res = s[-3:]
    print 'Case #%d: %s' % (case, res)
