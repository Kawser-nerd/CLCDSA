import itertools
import sys
restr = sys.argv[1]

def out(T):
    print " ".join( str(x) for x in T )

t = int(raw_input().strip())
for case in range(1, t+1):
    print 'Case #%d:' % case
    T = sorted([ int(x) for x in raw_input().strip().split(' ') ][1:])
    T = eval( 'T' + restr )
    D = dict()
    for subset in itertools.chain.from_iterable(itertools.combinations(T, r) for r in range(len(T)+1)):
        s = sum(subset)
        if s in D:
            out(subset)
            out(D[s])
            break
        D[s] = subset

sys.stderr.write( "KONIEC " + restr + "\n")
