#!/usr/bin/python

import sys

def getline():
    return sys.stdin.readline()[:-1]

def trace(*strs):
    return
    print >> sys.stderr, '>>',
    for str in strs:
        print >> sys.stderr, str,
    print >> sys.stderr

n_cases = int(getline())
for case_num in range(1,n_cases+1):
    trace( 'Case #', case_num )
    n_engines = int(getline())
    trace(n_engines, 'engines:')
    engine_names = [
        getline()
        for i in range(0,n_engines)
    ]
    trace( repr(engine_names) )

    n_queries = int(getline())
    trace(n_queries, 'queries:')
    queries = [
        getline()
        for i in range(0,n_queries)
    ]
    trace( repr(queries) )

    # I think a greedy algo will work.
    # i.e., at any point, simply pick the search engine
    # that avoids (is not named by) the longest prefix of
    # following queries.

    n_switches = 0

    posn = 0
    # posn is the offset of what has been dealt with,
    # and the index of the next query to be dealt with.
    while True:
        d = {}
        for i in range(posn,n_queries):
            q = queries[i]
            assert q in engine_names
            d[q] = 1
            if len(d) == n_engines:
                # queries[i-1] (offset i) is the farthest you can go,
                # and q names the engine you can do it with.
                trace('can get to offset', i, 'with', q, 'then you need to switch')
                assert i > posn
                posn = i
                # Switch!
                n_switches += 1
                break
        else:
            # can go to the end without needing to switch
            candidates = [ se for se in engine_names if se not in d ]
            trace('can get to end with any of', candidates)
            break
            
    print 'Case #%d: %d' % (case_num, n_switches)


assert sys.stdin.readline() == ''

# vim: sw=4 ts=4 expandtab
