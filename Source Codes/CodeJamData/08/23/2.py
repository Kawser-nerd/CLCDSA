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
        K = int(dat[0])
        print i
        dat = dat[1:]
        dis = map(int,dat[0].split(' '))
        dis = dis[1:]
        dat = dat[1:]
        res = solve(K,dis,i+1)
        results.append(res)

    return "\n".join(results)
        

##def solve2(K,dis,ind):
##    d = dict([(x,-1) for x in xrange(K)])
##    loc = 0
##    for i in xrange(1,K+1):
##        burn = i-1
##        for j in xrange(burn):
##            while(d[loc] != -1):
##                loc = (loc+1) % K
##            loc = (loc+1)%K
##        while(d[loc] != -1):
##            loc = (loc+1) % K
##        d[loc] = i
##        
##    ret = "Case #%d:" % (ind,)
##    for x in dis:
##        ret = ret+" %d" % d[x-1]
##    return ret
##    
def solve(K,dis,ind):
    d = []
    for i in xrange(K,0,-1):
        
        d = [i]+d
        ld = len(d)
        spl = (i-1) % ld
        d = d[ld-spl:]+d[:ld-spl]
    ret = "Case #%d:" % (ind,)
    for x in dis:
        ret = ret+" %d" % d[x-1]
    return ret
