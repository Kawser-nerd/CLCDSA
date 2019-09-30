#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

def case():
    a, b = line().split()
    return '%s %s' % solve(a, b)

cache = {}
def solve(a, b, cur=0):
    key = repr([a,b,cur])
    if key in cache:
        return cache[key]

    if not a:
        return '', ''
    da, db = a[0], b[0]
    cana = map(str, range(10)) if da == '?' else [da]
    canb = map(str, range(10)) if db == '?' else [db]
    pa = [None] * 3
    pb = [None] * 3
    for x in range(3):
        pa[x], pb[x] = solve(a[1:], b[1:], cur=x)
    solutions = []
    for mya in cana:
        for myb in canb:
            if cur == 2 or (cur == 0 and mya < myb):
                solutions.append((mya+pa[2], myb+pb[2]))
            elif cur == 1 or (cur == 0 and mya > myb):
                solutions.append((mya+pa[1], myb+pb[1]))
            else:
                assert cur == 0 and mya == myb
                solutions.append((mya+pa[0], myb+pb[0]))

    def solkey(s):
        a, b = s
        if cur == 1:
            a = '1' + a
            b = '0' + b
        elif cur == 2:
            a = '0' + a
            b = '1' + b
        return abs(int(a) - int(b)), int(a), int(b)

    result = min(solutions, key=solkey)
    #pprint([[s, solkey(s)] for s in solutions])
    #print "For %r vs %r with cur=%r: %r (key=%r)" % (a, b, cur, result, solkey(result))
    cache[key] = result
    return result

if __name__ == '__main__':
    main()
