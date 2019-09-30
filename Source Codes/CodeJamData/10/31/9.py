#!/usr/bin/python

import sys

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

def trace(*strs):
    print >> sys.stderr, '..',
    for str in strs:
        print >> sys.stderr, str,
    print >> sys.stderr

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            trace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            trace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    trace( 'Case #', case_num )

    a_ = []
    b_ = []
    N = int(getline())
    for i in range(N):
        (a,b) = map(int,getline().split())
        a_.append(a)
        b_.append(b)

    # N is at most 1000
    # so N^2 is on order of 1,000,000,
    # which seems tolerable
    n_intersections = 0
    for i in range(N):
        ai = a_[i]
        bi = b_[i]
        for j in range(i):
            # Do wires i and j intersect?
            aj = a_[j]
            bj = b_[j]
            if (ai < aj) == (bi < bj):
                # no intersection
                pass
            else:
                n_intersections += 1

    print 'Case #%d: %s' % (case_num, n_intersections)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
