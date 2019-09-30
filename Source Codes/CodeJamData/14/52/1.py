def reader(inFile):
    (P, Q, N) = inFile.getInts()
    return (P, Q, [tuple(inFile.getInts()) for i in xrange(N)])

from fractions import gcd

def solver((P, Q, monsters)):
    n = len(monsters)
    poss = set([(tuple([z[0] for z in monsters]),0)])
    while True:
        if set([a for b in poss for a in b[0]]) == set([0]):
            break
        #print poss
        poss = set([(tuple([max(i[k]-P,0) if k == j else i[k] for k in xrange(n)]),g+(monsters[j][1] if (j < n) and (i[j] <= P) else 0)) for (i,g) in poss for j in xrange(n+1) if (j == n) or (i[j] > 0)])
        #print poss
        poss = set([(tuple([max(i[k]-Q,0) if k == j else i[k] for k in xrange(n)]),g) for (i,g) in poss for j in [min([j2 for j2 in xrange(n+1) if (j2 == n) or (i[j2] > 0)])]])
        #print poss
    return max([z[1] for z in poss])

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2014/3/b/", "b").run()
