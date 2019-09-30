lines = open("A-large.txt").read().split("\n")
T = int(lines[0])

def f(R,C,grid):
    arrows = []
    for i,row in enumerate(grid):
        for j,item in enumerate(row):
            if item != '.':
                arrows.append((i,j,item))
    total = 0
    for i,j,arrow in arrows:
        ok = False
        if arrow=='v':
            for i2 in xrange(i+1,R):
                if grid[i2][j] != '.':
                    ok = True
        elif arrow=='^':
            for i2 in xrange(i):
                if grid[i2][j] != '.':
                    ok = True
        if arrow=='>':
            for j2 in xrange(j+1,C):
                if grid[i][j2] != '.':
                    ok = True
        elif arrow=='<':
            for j2 in xrange(j):
                if grid[i][j2] != '.':
                    ok = True
        if not ok:
            total += 1
            for i2 in xrange(i+1,R):
                if grid[i2][j] != '.':
                    ok = True
            for i2 in xrange(i):
                if grid[i2][j] != '.':
                    ok = True
            for j2 in xrange(j+1,C):
                if grid[i][j2] != '.':
                    ok = True
            for j2 in xrange(j):
                if grid[i][j2] != '.':
                    ok = True
            if not ok:
                return "IMPOSSIBLE"
    return total
curr_i = 1
for i in xrange(1,T+1):
    R,C = tuple(int(j) for j in lines[curr_i].split(' '))
    curr_i += 1
    out = f(R,C,lines[curr_i:curr_i+R])
    curr_i += R
    print "Case #%d: %s" % (i, out)