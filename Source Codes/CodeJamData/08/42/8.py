def area2(x1, y1, x2, y2, x3, y3):
    vx1 = x2 - x1
    vx2 = x3 - x1
    vy1 = y2 - y1
    vy2 = y3 - y1
    return abs(vx1*vy2 - vx2*vy1)

def find_v(N, M, A):
    for x1 in xrange(N+1):
        for y1 in xrange(M+1):
            for x2 in xrange(N+1):
                for y2 in xrange(M+1):
                    if(area2(0, 0, x1, y1, x2, y2) == A):
                        return (0, x1, x2, 0, y1, y2)
    return None
filename = "B-small-attempt0.in"
f = open(filename, 'r')
of = open("B-large.out", 'w')

C = int(f.readline())

for x in xrange(C):
    l = f.readline().split(' ')
    N = int(l[0])
    M = int(l[1])
    A = int(l[2])
    points = find_v(N, M, A)
    if(points != None):
        print >> of, "Case #%d: %d %d %d %d %d %d" % (x + 1, points[0], points[3], points[1], points[4], points[2], points[5])
    else:
        print >> of, "Case #%d: IMPOSSIBLE" % (x + 1)



