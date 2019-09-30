import sys

hexmap = {'0': (0,0,0,0), '1': (0,0,0,1), '2': (0,0,1,0), '3': (0,0,1,1),
          '4': (0,1,0,0), '5': (0,1,0,1), '6': (0,1,1,0), '7': (0,1,1,1),
          '8': (1,0,0,0), '9': (1,0,0,1), 'A': (1,0,1,0), 'B': (1,0,1,1),
          'C': (1,1,0,0), 'D': (1,1,0,1), 'E': (1,1,1,0), 'F': (1,1,1,1),
}


def print_grid(grid, rows, cols):
    for r in xrange(rows):
        print ' '.join(str(grid[r][c]) for c in xrange(cols))
        

class Board(object):
    def __init__(self, rows, cols, colors):
        self.rows = rows
        self.cols = cols
        self.grid = [[0]*cols for _ in xrange(rows)]
        self.rowruns = [[0]*cols for _ in xrange(rows)]
        self.colruns = [[0]*cols for _ in xrange(rows)]
        
        assert rows*cols==4*len(colors) and cols%4==0
        r = cindex = 0
        while r<rows:
            c = 0
            while c<cols:
                ch = colors[cindex]
                cindex += 1
                four = hexmap[ch]
                for incr in xrange(4):
                    self.grid[r][c+incr] = four[incr]
                c += 4
            r += 1
            
        #print "Board:"
        #print_grid(self.grid, self.rows, self.cols)
            
    def cut_next(self):
        best = None
        # recompute rowlength/collength
        for r in xrange(self.rows):
            for c in xrange(self.cols):
                self.rowruns[r][c] = self.colruns[r][c] = 0
                
        for r in xrange(self.rows):
            for c in xrange(self.cols):
                if self.grid[r][c]>=0:
                    # get length of good run of rows and cols
                    if self.rowruns[r][c]==0:
                        # stay in row and alternate colors in columns
                        run = 0
                        while True:
                            run += 1
                            if c+run>=self.cols or self.grid[r][c+run] != 1-self.grid[r][c+run-1]: break
                        for i in xrange(run):
                            self.rowruns[r][c+i] = run - i
                    
                    if self.colruns[r][c]==0:
                        # stay in column and alternate colors in rows
                        run = 0
                        while True:
                            run += 1
                            if r+run>=self.rows or self.grid[r+run][c] != 1-self.grid[r+run-1][c]: break
                        for i in xrange(run):
                            self.colruns[r+i][c] = run - i
        
        #print "Row runs:"
        #print_grid(self.rowruns, self.rows, self.cols)
        #print "Col runs:"
        #print_grid(self.colruns, self.rows, self.cols)        
          
        # now we have the number of good rows and columns starting from every cell
        for r in xrange(self.rows):
            for c in xrange(self.cols):
                size = min(self.rowruns[r][c], self.colruns[r][c])
                mincare = best[0] if best else 1
                while size>mincare:
                    good = True
                    # see if all squares in the row run are good for that many columns, and vice versa
                    for delta in xrange(1,size):
                        if self.colruns[r][c+delta]<size:
                            good = False
                            break
                        if self.rowruns[r+delta][c]<size:
                            good = False
                            break
                    if good:
                        break
                    size -= 1
                
                if size > 0 and ((best is None) or size > best[0]):
                    best = (size, r, c)
                    #print best
                    
        if not best: return None
        # perform cut by setting removed squares to -1
        for r in xrange(best[1], best[1]+best[0]):
            for c in xrange(best[2], best[2]+best[0]):
                self.grid[r][c] = -1
                      
        #print_grid(self.grid, self.rows, self.cols)
        return best[0]
        

def boardcuts(M, N, colors):
    cuts = {}
    board = Board(M, N, colors)
    while True:
        size = board.cut_next()
        if size is None: break
        cuts[size] = 1 + cuts.get(size,0)
        
    return cuts
    

infile = sys.stdin
T = int(infile.readline().strip())        
for i in xrange(T):
    M,N = map(int, infile.readline().strip().split())
    cstr = ''
    for j in xrange(M):
        cstr += infile.readline().strip()
    
    cuts = boardcuts(M, N, cstr)
    print("Case #%d: %s" % (i+1, str(len(cuts))))
    for size in reversed(sorted(cuts)):
        print("%d %d" % (size, cuts[size]))
    
