import psyco
psyco.full()

def area2(a, b, c):
    res = b[0]*a[1] - a[0]*b[1] + c[0]*b[1] - b[0] * c[1] + a[0] * c[1] - c[0] * a[1]
    return res

def solve():
    for case in xrange(input()):
        n, m, a = [int(s) for s in raw_input().split()]

        tri = None
        if a <= n * m:
            for ax in xrange(0,n+1):
                if tri: break
                for ay in xrange(0,m+1):
                    if tri: break
                    for bx in xrange(0,n+1):
                        if tri: break
                        for by in xrange(0,m+1):
                            cx = 0
                            cy = 0
                            if area2((ax, ay), (bx, by), (cx, cy)) == a:
                                tri = [ax, ay, bx, by, cx, cy]
                                    
        if tri is None:
            res = 'IMPOSSIBLE'
        else:
            res = ' '.join(str(i) for i in tri)

        print 'Case #%d: %s' % (case+1, res)

solve() # so that psyco can do its magic
