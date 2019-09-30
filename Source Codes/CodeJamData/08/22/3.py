case = "small-attempt0"
input_file = "B-%s.in" % case
output_file = "B-%s.out" % case

fin = open(input_file)
fout = open(output_file, "w")

def multCount(a, b, m):
    return b/m - (a-1)/m

def getRoot(DS, x):
    if DS[x] != x:
        DS[x] = getRoot(DS, DS[x])
    return DS[x]

def join(DS, a, b):
    a = getRoot(DS, a)
    b = getRoot(DS, b)
    if a != b:
        DS[a] = b

def sieve(lim):
    n = lim + 1
    prime = [True] * n
    prime[0], prime[1] = False, False
    for i in xrange(n):
        if prime[i]:
            for j in xrange(2*i, n, i):
                prime[j] = False
    return [p for p in xrange(n) if prime[p]]

primes = sieve(1000)

ncase = int(fin.readline().strip())

for z in xrange(1, ncase+1):
    print "Case %d" % z
    A, B, P = [int(x) for x in fin.readline().strip().split()]
    pprimes = [p for p in primes if p >= P and multCount(A, B, p) > 1]
    DS = range(len(pprimes))
    for pi in xrange(len(pprimes)):
        ppi = pi + 1
        while ppi < len(pprimes) and pprimes[pi]*pprimes[ppi] <= B:
            if multCount(A, B, pprimes[pi]*pprimes[ppi]) > 0:
                join(DS, pi, ppi)
            ppi += 1
    div = [False] * (B - A + 1)
    for p in pprimes:
        for i in xrange(((A-1)/p+1)*p, B+1, p):
            div[i-A] = True
    res = len([x for x in div if not x]) + len([x for x in range(len(DS)) if x == DS[x]])
    print >> fout, "Case #%d:" % z, res

fin.close()
fout.close()
