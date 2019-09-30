#!/usr/bin/python

import sys, math

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

    (L,P,C) = map(int, getline().split())

    # L * C^k ~ P
    # C^k ~ P/L
    # k log C ~ (log P - log L)
    # k ~ (log P - log L) / log C
    trace( 'L=%s P=%s C=%s' % (L,P,C) )
    log_span = ( math.log(P) - math.log(L) ) / math.log(C)
    trace( 'log_span =', log_span )

    # and then we can do a binary search on log_span
    n_load_tests_A = int(math.ceil( math.log(log_span,2) - 1e-7 ))

    # ---------------

    for i in xrange(sys.maxint):
        if pow(C, pow(2,i)) * L >= P:
            n_load_tests = i
            break

    if n_load_tests_A != n_load_tests:
        trace('!!!', n_load_tests_A, '!=', n_load_tests )

    print 'Case #%d: %s' % (case_num, n_load_tests)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
