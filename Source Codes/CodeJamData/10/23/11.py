import math, sys

def comb(n, k, cache={}): # n over k mod 100003
    if k > n:
        return 0
    if k < 0:
        return 0
    
    if (n,k) in cache:
        return cache[n,k]
    
    r = (math.factorial(n) / math.factorial(k) / math.factorial(n-k)) % 100003
    cache[n,k] = r
    return r
    
# m[k,l] -- the number of subsets of size k ending in l (k<=l-1)
n = 500
m = {}
for l in xrange(2, n+1):
    m[1,l] = 1

for k in xrange(2, n):
    print >>sys.stderr, k
    for l in xrange(k+1, n+1):
        s = 0
        for q in xrange(1, k):
            s += m[q,k] * comb(l-k-1, k-q-1)
        m[k,l] = s % 100003

fin = open('in', 'r')
test_count = int(fin.readline().rstrip())
for c in xrange(test_count):
    n = int(fin.readline().rstrip())

    res = 0
    for k in xrange(1, n):
        res += m[k,n]
        
    print 'Case #%d: %d' % (c+1, res % 100003)
