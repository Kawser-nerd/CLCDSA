#!/usr/bin/env python

import sys
import re
from subprocess import Popen, PIPE, STDOUT

stdin = sys.stdin

cases = int(stdin.readline())

solved_re = re.compile(r'.*Value of objective function: ([0-9.e+]+)$')
for case in range(1, cases+1):
    p = int(stdin.readline())
    misses = [p - int(x) for x in stdin.readline().split()]
    assert len(misses) == 1 << p
    rounds = []
    lp = 'min:\n'
    for i in range(p):
        r = [int(x) for x in stdin.readline().split()]
        rounds.append(r)
        for j, cost in enumerate(r):
            lp += '\t%d * r%d%d + \n' % (cost, i, j)
    lp += '\t0;\n\n'

    for i in range(1 << p):
        v = i
        for j in range(len(rounds)):
            v >>= 1
            lp += 'r%d%d + ' % (j, v)
        lp += '0 >= %d;\n' % misses[i]

    lp += '\n\n'

    for i, r in enumerate(rounds):
        for j in range(len(r)):
            lp += 'r%d%d >= 0;\n' % (i, j)
            lp += 'r%d%d <= 1;\n' % (i, j)

    for i, r in enumerate(rounds):
        for j in range(len(r)):
            lp += 'int r%d%d;\n' % (i, j)

    result = Popen(['lp_solve', '-S1'], stdin=PIPE, stdout=PIPE, stderr=STDOUT).communicate(lp)[0]

    g = solved_re.search(result)
    assert g is not None
    print 'Case #%d: %d' % (case, int(round(float(g.group(1)))))

