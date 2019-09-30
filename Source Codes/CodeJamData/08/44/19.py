
from math import log

def dofile(fname,outfname):
    result = dostr(file(fname).read())
    file(outfname,'w').write(result)

def dostr(s):
    dat = s.splitlines()

    #split to data sets
    N = int(dat[0])
    dat = dat[1:]
    results = []
    for i in xrange(N):
        k = int(dat[0])
        dat = dat[1:]
        s = dat[0].strip()
        dat = dat[1:]
        results.append(solve(k,s,i+1))

    return '\n'.join(results)


perm = []

def solve(k,s,ind):
    global perm
    print k,len(s),ind
    blocks = [s[k*i:k*(i+1)] for i in xrange(len(s)/k)]
    minSize = len(s)

    for a in xrange(k):
        for b in xrange(k):
            for c in xrange(k):
                for d in xrange(k):
                    for e in xrange(k):
                        perm = [a,b,c,d,e][:k]
                        if len(set(perm)) != k:
                            continue
                        x = score("".join(map(mype, blocks)))
                        if x < minSize:
                            minSize = x
                        
                        
    res = minSize
    
    return "Case #%d: %d" % (ind, res)
    

def mype(block):
    ret = ""
    for x in perm:
        ret = ret+block[x]
    return ret

def score(s):
    ret = 1
    cur = s[0]
    for x in s[1:]:
        if x != cur:
            ret+= 1
        cur = x
    return ret
