import psyco

def proxy(function):
    return psyco.proxy(function)

class Case:
    def __init__(self, s, caseNum):
        self.caseNum = caseNum
        self.R = int(s.read())
        self.data = [[int(x) for x in row.split(" ")] for row in s.readList(self.R)]

    @proxy
    def solve(self):
        grid = [[False for unused_a in xrange(110)] for unused_b in xrange(110)]
        for data_row in self.data:
            for x in xrange(data_row[0], data_row[2] + 1):
                for y in xrange(data_row[1], data_row[3] + 1):
                    grid[y][x] = True
        return self.solve_grid(grid) 
        
    @proxy
    def solve_grid(self, grid):
        has_data = False
        for row in grid:
            if row.__contains__(True):
                has_data = True
                break
        if not has_data:
            return 0
        grid2 = [[False for unused_a in xrange(110)] for unused_b in xrange(110)]
        for row in xrange(1, len(grid)):
            for col in xrange(1, len(grid)):
                if grid[row - 1][col] and grid[row][col - 1]:
                    grid2[row][col] = True
                if grid[row - 1][col] and grid[row][col]:
                    grid2[row][col] = True
                if grid[row][col - 1] and grid[row][col]:
                    grid2[row][col] = True
        return 1 + self.solve_grid(grid2)
    
    def __repr__(self):
        return "Problem C Case %d" % self.caseNum

class Contents:
    def __init__(self, f):
        self.data = [line.strip() for line in f]
        self.i = 0

    def read(self):
        return self.readList(1)[0]

    def readList(self, len):
        result = self.data[self.i : self.i + len]
        self.i += len
        return result

def run():
    import sys
    f = file(sys.argv[1])
    s = Contents(f)
    numCases = int(s.read())
    
    for caseNum in range(numCases):
        case = Case(s, caseNum)
        print "Case #%d: %s" % (caseNum + 1, case.solve())
        sys.stdout.flush()
        
if __name__ == "__main__":
    run()