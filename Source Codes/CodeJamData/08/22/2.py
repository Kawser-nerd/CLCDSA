def dofile(infile, outfile):
    instr = file(infile).read()
    ostr = dostr(instr)
    file(outfile,"w").write(ostr)

def eat(l,n):
    return l[:n],l[n:]

def dostr(dat):
    dat = dat.splitlines()
    N = int(dat[0])
    dat = dat[1:]
    results = []
    for i in xrange(N):
        A,B,P = map(int,dat[0].split(' '))
        dat = dat[1:]
        res = solve(A,B,P,i+1)
        results.append(res)

    return "\n".join(results)
        

def isPrime(x):
    for i in xrange(2,x):
        if x % i == 0:
            return False
    return True

def solve(A,B,P,ind):
    primes = [x for x in xrange(P,B+1) if isPrime(x)]
    sets = [set([x,]) for x in xrange(A,B+1)]
    for p in primes:
        sets2 = []
        newset = set()
        for s in sets:
            merge = True
            for i in s:
                if i % p == 0:
                    newset = newset.union(s)
                    merge=False
                    break
            if merge:
                sets2.append(s)
        if len(newset) > 0:
            sets2.append(newset)
        sets = sets2
    print sets
    res = len(sets)
    return "Case #%d: %d" % (ind, res)
    
