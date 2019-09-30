#!/usr/bin/env python

import sys

def read_int():
    return int( sys.stdin.readline().strip() )

def read_int_list():
    return [ int( x ) for x in sys.stdin.readline().strip().split() ]

N = read_int()

for i in range( N ):

    P, K, L = read_int_list()
    frequencies = read_int_list()
    frequencies.sort()
    frequencies.reverse()
    while frequencies[ -1 ] == 0:
        frequencies.pop()

    if P*K < len( frequencies ):
        result = 'Impossible'
    else:
        button = 0
        count = 1
        result = 0
        for f in frequencies:
            result += count*f
            button += 1
            if button == K:
                button = 0
                count += 1
                
    print 'Case #%i: %s' % ( i + 1, result )

