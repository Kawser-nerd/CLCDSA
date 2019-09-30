def solve(n):
    digs=set()
    for i in xrange(1,1000):
        for j in str(i*n):
            digs.add(j)
        if(len(digs)==10):
            return i*n
    return "INSOMNIA"
t=int(raw_input())
for cas in xrange(1,t+1):
    n=int(raw_input())
    print "Case #{}: {}".format(cas,solve(n))
