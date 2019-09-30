def solve():
    f = open('B-large.in')
    g = open('B.out','w')
    N = int(f.readline())
    for i in range(N):
        s = f.readline().strip()
        D = len(s)
        m = [[]*210]*D
        def go(j):
            rn = [0]*210
            if j == D : return rn
            if m[j] != [] : return m[j]
            t = int(s[j:D])
            rn[t%210] +=1
            for k in xrange(j+1,D):
                t = int(s[j:k])
                rs = go(k)
                for ir in xrange(210):
                    rn[(t+ir)%210] += rs[ir]
                    rn[(210+t-ir)%210] += rs[ir]
            m[j] = rn
            return rn
        rrr = go(0)
        ret = 0
        for j in xrange(210) :
            if j%2==0 or j%3==0 or j%5==0 or j%7==0 :
                ret+=rrr[j]
        #print ret
        g.write('Case #%d: %d\n' % (i+1, ret))
    g.close()
solve()