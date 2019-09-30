
def process(n, m, a):
    if n * m < a: return None
    for x1 in xrange(n+1):
        for y1 in xrange(m+1):
            # we have one segment: (0,0)-(x1,y1)
            for x2 in xrange(max(x1-n,-n), min(x1+n,n)+1):
                for y2 in xrange(max(y1-m,-m), min(y1+m,m)+1):
                    if abs(x2 * y1 - y2 * x1) == a:
                        xmin = -min(0, x1, x2)
                        ymin = -min(0, y1, y2)
                        return ((xmin, ymin), (x1+xmin, y1+ymin), (x2+xmin, y2+ymin))
    return None

import sys
next = iter(sys.stdin).next
ncases = int(next())
for i in xrange(ncases):
    n, m, a = map(int, next().split())
    coords = process(n, m, a)
    if coords is None:
        print 'Case #%d: IMPOSSIBLE' % (i+1)
    else:
        assert abs((coords[2][0]-coords[0][0]) * (coords[1][1]-coords[0][1]) -
                   (coords[1][0]-coords[0][0]) * (coords[2][1]-coords[0][1])) == a
        print 'Case #%d: %d %d %d %d %d %d' % (i+1, coords[0][0], coords[0][1],
                coords[1][0], coords[1][1], coords[2][0], coords[2][1])
    sys.stdout.flush()



