def solve():
    r,c,d = map(int,raw_input().split())
    a = [map(int,raw_input()) for _ in xrange(r)]
    for k in xrange(min(r,c),2,-1):
        #print k
        for x in xrange(r-k+1):
            for y in xrange(c-k+1):
                #print x,y
                sx=sy=0
                for i in xrange(k):
                    for j in xrange(k):
                        if i==0 and (j==0 or j==k-1): continue
                        if i==k-1 and (j==0 or j==k-1): continue
                        #print i,j,a[x+i][y+j]
                        sx += (i-.5*k+.5)*a[x+i][y+j]
                        sy += (j-.5*k+.5)*a[x+i][y+j]
                #print sx,sy
                if sx==sy==0: return k
    return "IMPOSSIBLE"

t = input()
for i in xrange(t):
    print "Case #%d: %s"%(i+1,solve())
