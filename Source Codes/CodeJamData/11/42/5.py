import sys
import collections

infile = sys.stdin

def find_blade(grid, R, C):
    for k in xrange(min(R,C), 2, -1):
        cx = (k-1) / 2.0
        cy = (k-1) / 2.0
        for xstart in xrange(0, R-k+1):
            for ystart in xrange(0, C-k+1):
                mx = my = 0
                for dx in xrange(k):
                    for dy in xrange(k):
                        if (dx==0 or dx==k-1) and (dy==0 or dy==k-1):
                            # corner, don't count
                            pass
                        else:
                            mass = grid[xstart+dx][ystart+dy]
                            mx += (cx-dx) * mass
                            my += (cy-dy) * mass
                if abs(mx)<1e-5 and abs(my)<1e-5:
                    return k       
    return 0

T = int(infile.readline())
for i in xrange(T):
    R, C, D = map(int, infile.readline().split())
    grid = []
    for r in xrange(R):
        deltas = map(int, infile.readline().strip())
        grid.append([D+d for d in deltas])
    
    result = find_blade(grid, R, C)
    print("Case #%d: %s" % (i+1, result if result else "IMPOSSIBLE"))
