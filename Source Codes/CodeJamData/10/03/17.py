import heapq
import sys

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
        self.R, self.K, self.N = map(int, s.read().split(" "))
        self.items = map(int, s.read().split(" "))

    def solve(self):
        index = 0
        self.rides_left = self.R
        total = 0
        while self.rides_left > 0:
            count, new_index, original_rides_left = self.solve_at(index)
            if self.rides_left != original_rides_left:                
                length = original_rides_left - self.rides_left
                completes = (self.rides_left / length)
                remainder = self.rides_left % length
                index = new_index
                for i in xrange(length - 1):
                    next, index, z = self.solve_at(index)
                    count += next
                total += count * completes
                for i in xrange(remainder):
                    next, index, z = self.solve_at(index)
                    total += next
                return "%d" % total
            else:
                index = new_index
            total += count
            self.rides_left -= 1
        return "%d" % total
    
    @memoize
    def solve_at(self, index):
        start_index = index
        count = 0
        while count + self.items[index] <= self.K:
            count += self.items[index]
            index = (index + 1) % self.N
            if index == start_index:
                break
        return (count, index, self.rides_left)
        
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