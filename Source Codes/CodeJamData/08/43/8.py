def solve():
    f = open('C-small.in')
    g = open('C.out','w')
    T = int(f.readline())
    for k in range(T):
        N = int(f.readline())
        ps = []
        for j in xrange(N) :
            ps += [map(int,f.readline().split())]
        def test(d):
            d1mn, d2mn, d3mn, d4mn = 10**12, 10**12, 10**12, 10**12
            d1mx, d2mx, d3mx, d4mx = 0, 0, 0, 0
            for i in xrange(N):
                d1mn = min(d1mn, ps[i][0]+ps[i][1]+ps[i][2]+d*ps[i][3])
                d1mx = max(d1mx, ps[i][0]+ps[i][1]+ps[i][2]-d*ps[i][3])
                d2mn = min(d2mn, ps[i][0]+ps[i][1]-ps[i][2]+d*ps[i][3])
                d2mx = max(d2mx, ps[i][0]+ps[i][1]-ps[i][2]-d*ps[i][3])
                d3mn = min(d3mn, ps[i][0]-ps[i][1]+ps[i][2]+d*ps[i][3])
                d3mx = max(d3mx, ps[i][0]-ps[i][1]+ps[i][2]-d*ps[i][3])
                d4mn = min(d4mn, -ps[i][0]+ps[i][1]+ps[i][2]+d*ps[i][3])
                d4mx = max(d4mx, -ps[i][0]+ps[i][1]+ps[i][2]-d*ps[i][3])
            if d1mn<d1mx : return 0
            if d2mn<d2mx : return 0
            if d3mn<d3mx : return 0
            if d4mn<d4mx : return 0
            return 1
        def go():
            mn = 0.0
            mx = 3*1000000.0
            if test(mn) : return mn
            while(mx-mn > 0.0000001):
                d = (mx+mn)/2
                t = test(d)
                if t : mx = d
                else : mn = d
            return d
        
        ret = go()
        g.write('Case #%d: %.6f\n' % (k+1, ret))
    f.close()
    g.close()
solve()