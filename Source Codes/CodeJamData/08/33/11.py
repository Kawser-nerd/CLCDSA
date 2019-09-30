#!/usr/bin/env python

import sys

def read_int():
    return int( sys.stdin.readline().strip() )

def read_int_list():
    return [ int( x ) for x in sys.stdin.readline().strip().split() ]

N = read_int()

for k in range( N ):
    n, m, X, Y, Z = read_int_list()
    A = []
    for i in range( m ):
        A.append( read_int() )
    sequence = []
    for i in range( n ):
        sequence.append( int( A[ i % m ] ) )
        A[ i % m ] = int( ( X*A[ i % m ] + Y*( i + 1) ) % Z )

    counts = {}
    for s in reversed( sequence ):
        t = 1
        for i in counts.keys():
            if i > s:
                t += counts[ i ]
        if counts.has_key( s ):
            counts[ s ] += t
        else:
            counts[ s ] = t
    print 'Case #%i: %i' % ( k + 1, sum( counts.values() ) % 1000000007 )

