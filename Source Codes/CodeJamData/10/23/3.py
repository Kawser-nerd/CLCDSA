#!/usr/bin/env python

import pickle

import os


modulo = 100003

combtable = {}

for i in xrange(0, 1000):
    for j in xrange(0, i+1):
        if j == 0 or i == j:
            combtable[ (i, j) ] = 1
        else:
            combtable[ (i,j) ] = (combtable[ (i-1,j-1) ] + combtable[ (i-1, j) ]) % modulo

D = {}
if os.path.exists('cached'):
    D = pickle.loads(file('cached', 'rb').read())
else:
    for n in xrange(2, 501):
        for l in xrange(1, n):
            if l == 1:
                D[ (n, l) ] = 1
            else:
                result = 0
                for m in xrange(1, l):
                    bucket = (n-1) - (l+1) +1
                    pick = (l-1) - (m+1) + 1
                    if bucket >= pick:
                        result += D[ (l, m) ] * combtable[ (n-l-1, l-m-1) ]

                D[ (n, l) ] = result % modulo
    file('cached', 'wb').write(pickle.dumps(D))


c = raw_input()

for cs in xrange(1, int(c)+1):
    n = int(raw_input())
    result = 0
    for l in xrange(1, n):
        result += D[ (n, l) ]

    print "Case #%d: %d" % (cs, result % modulo)

            
