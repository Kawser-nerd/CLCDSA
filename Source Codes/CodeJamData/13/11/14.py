f = open('A-large.in')
t = int(f.readline())
for i in range(1,t+1):
    r, t = f.readline().split()
    r=int(r)
    t=int(t)
    t-=2*r+1

    L=0
    R=t
    while L<R:
        m=(L+R+1)/2
        if t>=m*(2*m+2*r+3):
            L=m
        else:
            R=m-1
    print 'Case #%d: %d'%(i,L+1)