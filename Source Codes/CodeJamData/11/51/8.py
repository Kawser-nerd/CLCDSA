eps=1e-12
def solve():
    w,l,u,g = map(int,raw_input().split())
    L = [map(int,raw_input().split()) for i in xrange(l)]
    U = [map(int,raw_input().split()) for i in xrange(u)]
    w+=1
    h = [0.]*w
    hl = [0.]*w
    for i in xrange(1,l):
        dx = L[i][0]-L[i-1][0]
        d = 1.*(L[i][1]-L[i-1][1])/dx
        for x in xrange(dx+1):
            h[x+L[i-1][0]]=x*d+L[i-1][1]
    l,L=u,U
    for i in xrange(1,l):
        dx = L[i][0]-L[i-1][0]
        d = 1.*(L[i][1]-L[i-1][1])/dx
        for x in xrange(dx+1):
            hl[x+L[i-1][0]]=x*d+L[i-1][1]
    h = [x-y for x,y in zip(hl,h)]
    a = sum((h[i]+h[i-1])*.5 for i in xrange(1,w))
    d = a/g
    r = []
    i = 0
    c = 0
    while len(r)<g-1:
        if c>=d-eps:
            ll,rr=0.,1.
            while rr-ll>1e-8:
                m = (rr+ll)*.5
                ap = ((h[i]-h[i-1])*(1-m)+h[i-1]+h[i])*m*.5
                if c-d>ap: ll =m
                else: rr=m
            r.append(i-ll)
            c-=d
            continue
        i+=1
        if i>=w: break
        hh = (h[i]+h[i-1])*.5
        c += hh
    return '\n'.join('%.8f'%x for x in r)

t = input()
for i in xrange(t):
    print "Case #%d:\n%s"%(i+1,solve())
