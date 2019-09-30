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
        n,A,B,C,D,x0,y0,M = map(int,dat[0].split(' '))
        dat = dat[1:]
        res = solve(n,A,B,C,D,x0,y0,M,i+1)
        results.append(res)

    return "\n".join(results)
        
def over(n,k):
    res = 1
    if (k>n):
        return 0
    for i in xrange(k):
        res *= n-i
    for i in xrange(k):
        res /= (i+1)
    return res

def solve(n,A,B,C,D,x0,y0,M,ind):
    X = x0 % M
    Y = y0 % M
    coord = dict()
    for i in xrange(n):
        mx = X % 3
        my = Y % 3
        coord[(mx,my)] = coord.get((mx,my),0) + 1
        X = (A*X+B) % M
        Y = (C*Y+D) % M
    res = 0
    print coord
    d = coord
    for x1 in xrange(3):
        for x2 in xrange(3):
            for x3 in xrange(3):
                for y1 in xrange(3):
                    for y2 in xrange(3):
                        for y3 in xrange(3):
                            if ((x1+x2+x3) %3 != 0) or ((y1+y2+y3) %3 != 0):
                                continue
                            if (x2 < x1) or (x3<x2) or (x2==x1 and y2<y1) or (x2==x3 and y3<y2):
                                continue
                            if (x1,y1) == (x2,y2) and (x2,y2)==(x3,y3):
                                res += over(d.get((x1,y1),0),3)
                            if (x1,y1) != (x2,y2) and (x2,y2)==(x3,y3):
                                res += d.get((x1,y1),0) * over(d.get((x2,y2),0),2)
                            if (x1,y1) == (x2,y2) and (x2,y2)!=(x3,y3):
                                res += d.get((x3,y3),0) * over(d.get((x2,y2),0),2)
                            if (x1,y1) != (x2,y2) and (x2,y2)!=(x3,y3):
                                print x1,y1,x2,y2,x3,y3
                                res += d.get((x1,y1),0) * d.get((x2,y2),0) * d.get((x3,y3),0)
                    
    return "Case #%d: %d" % (ind, res)
    
