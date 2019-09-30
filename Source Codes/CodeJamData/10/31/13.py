import sys

infile = sys.stdin
ntests = int(infile.readline().strip())        
for i in xrange(ntests):
    N = int(infile.readline().strip()) 
    points = []
    for j in xrange(N):
        points.append(map(int, infile.readline().strip().split()))

    intersections = 0
    # N^2 but should be ok
    for ii in xrange(N):
        a1, b1 = points[ii]
        for jj in xrange(ii+1, N):
            a2, b2 = points[jj]
            if (a1>a2 and b1<b2) or (a1<a2 and b1>b2):
                intersections += 1
            
    print("Case #%d: %s" % (i+1, str(intersections)))
    