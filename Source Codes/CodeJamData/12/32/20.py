import sys, math

f = sys.stdin
T = int(f.readline())
for tc in xrange(1,T+1):
    print 'Case #%d:' % tc
    l = f.readline().split()
    D = float(l[0])
    N,A = int(l[1]),int(l[2])
    Nl = []
    for i in range(N):
        Nl.append( tuple([float(val) for val in f.readline().split()]) )
    Al = [float(val) for val in f.readline().split()]
    if N == 1:
        for ai in Al:
            print math.sqrt(2 * D / ai)
    elif N == 2:
        v0 = (Nl[1][1] - Nl[0][1])/(Nl[1][0] - Nl[0][0])
        for ai in Al:
            tcar = (D-Nl[0][1])/v0
            print max([math.sqrt(2 * D / ai), tcar])


