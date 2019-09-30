def reader(inFile):
    N = inFile.getInt()
    return [inFile.getInts() for i in xrange(N)]

from sys import stderr
from fractions import Fraction

def cross(pts, a, b, c, d):
    a = pts[a]
    b = pts[b]
    c = pts[c]
    d = pts[d]
    
    d = [d[i] - a[i] for i in xrange(2)]
    c = [c[i] - a[i] for i in xrange(2)]
    b = [b[i] - a[i] for i in xrange(2)]
    a = [a[i] - a[i] for i in xrange(2)]
    
    d = [b[0] * d[0] + b[1] * d[1], b[1] * d[0] - b[0] * d[1]]
    c = [b[0] * c[0] + b[1] * c[1], b[1] * c[0] - b[0] * c[1]]
    b = [b[0] * b[0] + b[1] * b[1], b[1] * b[0] - b[0] * b[1]]
    
    if (c[1] == d[1]):
        if (c[1] == 0):
            if min(c[0], d[0]) > b[0]:
                return False
            if max(c[0], d[0]) < 0:
                return False
            return True
        return False
    
    if (c[1] * d[1] > 0):
        return False
    f = c[0] + Fraction((0 - c[1]) * (d[0] - c[0]), d[1] - c[1])
    return (0 <= f) and (f <= b[0])

def twiceArea(pts, seq):
    return abs(sum([pts[seq[i]][0] * pts[seq[i-1]][1] - pts[seq[i]][1] * pts[seq[i-1]][0] for i in xrange(len(seq))])) 

def solver(pts):
    N = len(pts)
    routes = [[j,0,i] for i in xrange(1,N) for j in xrange(i+1,N)]
    for i in xrange(3,N):
        routes = [route + [k] for route in routes for k in xrange(1,N) if (k not in route) and (len([h for h in xrange(i-2) if cross(pts, route[h], route[h+1], route[-1], k)]) == 0)]
    routes = [route for route in routes if len([i for i in xrange(1, N - 2) if cross(pts, route[0], route[N - 1], route[i], route[i + 1])]) == 0]
    areas = [twiceArea(pts,route) for route in routes]
    mx = max(areas)
    return " ".join([str(k) for k in routes[areas.index(mx)]])

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/lpebody/gcj/2013_3/b/", "b").run()

# (0,2) (0,0) (1,1) (2,2) (2,0)

