import sys
sys.setrecursionlimit(5000)
import psyco

def proxy(function):
    return psyco.proxy(function)

def memoize(function):
    cache = {}
    def decorated_function(*args):
        if args in cache:
            return cache[args]
        else:
            val = function(*args)
            cache[args] = val
            return val
    return decorated_function

class Case:
    def __init__(self, s, caseNum):
        self.caseNum = caseNum
        self.P = int(s.read())
        self.missables = [int(x) for x in s.read().split(" ")]
        self.costs = [[int(x) for x in line.split(" ")] for line in s.readList(self.P)]

    def solve(self):                        
        return self.solve_from_bottom(self.P - 1, 0, tuple(self.missables))
        
    @memoize
    @proxy
    def solve_from_bottom(self, costs_row, costs_base_col, missables):
        for entry in missables:
            if entry < 0:
                return 10000000000000000000
        if costs_row < 0:
            return 0
        candidate_count = len(missables)
        cost = self.costs[costs_row][costs_base_col] + self.solve_from_bottom(costs_row - 1, 2 * costs_base_col, missables[:len(missables)/2]) + self.solve_from_bottom(costs_row - 1, 2*costs_base_col + 1, missables[len(missables)/2:])
        length = 1 << costs_row
        missables2 = list(missables[:len(missables)/2])
        for i in xrange(len(missables2)):
            missables2[i] -= 1
        missables2 = tuple(missables2)            
        cost2 = self.solve_from_bottom(costs_row - 1, 2 * costs_base_col, missables2)
        missables2 = list(missables[len(missables)/2:])
        for i in xrange(len(missables2)):
            missables2[i] -= 1
        missables2 = tuple(missables2)            
        cost2 += self.solve_from_bottom(costs_row - 1, 2*costs_base_col + 1, missables2)
        if cost < cost2:
            return cost
        return cost2  
        
    def __repr__(self):
        return "Problem B Case %d" % self.caseNum

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
    f = file(sys.argv[1])
    s = Contents(f)
    numCases = int(s.read())
    
    for caseNum in range(numCases):
        case = Case(s, caseNum)
        print "Case #%d: %s" % (caseNum + 1, case.solve())
        sys.stdout.flush()
        
if __name__ == "__main__":
    run()