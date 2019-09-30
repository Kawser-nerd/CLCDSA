import sys
fin = file(sys.argv[1], 'r')
T = int(fin.readline())

def fact(n):
    if n < 2: return 1
    return reduce(lambda x,y: x*y, (i for i in xrange(2,n+1)))

def comb(n, k):
    if k > n/2:
        k = n - k
    if k == 0: return 1
    r = reduce(lambda x,y: x*y, (i for i in xrange(n-k+1, n+1)))/ fact(k)
    #print 'C(%d, %d) = %d' % (n, k, r)
    return r

for t in xrange(1, T+1):
    C, N = [int(x) for x in fin.readline().split()]

    cache = {}
    def comb2(k, v):
        #how to choose v new cards, if k cards is actually known
        if (k, v) in cache:
            return cache[k, v]
        r = comb(C-k, v) * comb(k, N-v)
        cache[k, v] = r
        return r
    c_new = float(comb(C, N))

    def p_k_new(k, v):
        return float(comb2(k, v)) / c_new

    known = [0.0 for c in xrange(C+1)]
    known[N] = 1.0
    package = 1
    res = 0.0
    while True:
        package += 1
        m = 0.0
        known2 = [0.0 for c in xrange(C+1)]
        for k in xrange(N, C):
            p = known[k]
            if p == 0.0:
                continue
            for v in xrange(0, min(N, C-k)+1):
                a = p*p_k_new(k, v)
                m = max(m, a)
                known2[k+v] += a
        known = known2
        res += known[C] * package
        if m < 1e-6:
            break
    if  C == N: res = 1.0
    print 'Case #%d: %.6f' % (t, res)
