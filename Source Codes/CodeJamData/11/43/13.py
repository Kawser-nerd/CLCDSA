def primes(n):
    pr = range(n)
    for i in xrange(2,n):
        if not pr[i]: continue
        ii=i*i
        if ii>n: break
        pr[ii::i]=[0]*len(pr[ii::i])
    return filter(None,pr)[1:]

pr = primes(1000001)

def solve(n):
    r = 0
    if n<=1: return 0
    for p in pr:
        s = p*p
        if s>n: break
        while s<=n:
            r+=1
            s*=p
    return r+1

t = input()
for i in xrange(t):
    n = input()
    print "Case #%d: %d"%(i+1,solve(n))
