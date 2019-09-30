infile = open('square_tiles.in')
outfile = open('square_tiles.out', 'w')

T = int(infile.readline().strip())

def fill_spot(i, j):
    if i >= R - 1 or j >= C - 1:
        return False

    for i2 in xrange(i, i + 2):
        for j2 in xrange(j, j + 2):
            if grid[i2][j2] != '#':
                return False

    grid[i][j] = '/'
    grid[i][j + 1] = '\\'
    grid[i + 1][j] = '\\'
    grid[i + 1][j + 1] = '/'
    return True

def convert_to_red():
    for i in xrange(R):
        for j in xrange(C):
            if grid[i][j] == '#':
                if not fill_spot(i, j):
                    return False
    return True

for t in xrange(T):
    R, C = [int(s) for s in infile.readline().strip().split()]
    grid = [list(infile.readline().strip()) for i in xrange(R)]
        
    outfile.write('Case #%d:\n' % (t + 1))
    if not convert_to_red():
        outfile.write('Impossible\n')
        continue
    for i in xrange(R):
        outfile.write(''.join(grid[i]) + '\n')
