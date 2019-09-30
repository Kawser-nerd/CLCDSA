#!/usr/bin/python

from sol import *

def find_primes(to):
    bad = [False for x in range(to+1)]
    primes = []

    for x in range(2,to+1):
        if not bad[x]:
            primes.append(x)

            act = x
            while act <= to:
                bad[act] = True
                act += x

    return primes

pp = find_primes(1000000)

parent = []
def find_root( x ):
    global parent
    if parent[x] == x:
        return x

    root = find_root( parent[x] )
    parent[x] = root
    return root

def join( a, b ):
    global parent
    root_b = find_root(b)
    parent[ find_root(a) ] = root_b
    parent[ a ] = root_b


c = next_int()


for x in range(1,c+1):
    A,B,P =  [ next_int() for i in range(3) ]

    parent = [ y-A for y in range(A,B+1) ]

    for p in pp:
        if p < P:
            continue
        first = A + (p - A % p) % p

        act = first + p
        while act <= B:
            join( first-A, act-A )
            act += p

    res = sum( 1 if parent[x]==x else 0 for x in range(len(parent)) )

    print 'Case #%d: %d' % (x, res)
