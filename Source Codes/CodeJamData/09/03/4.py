import heapq
import sys
sys.setrecursionlimit(10000)

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
        self.string = s.read()

    def solve(self):
        return "%04d" % (self.count_find("welcome to code jam", self.string) % 10000)
    
    @memoize
    def count_find(self, sub, string):
        if len(sub) == 0 or len(sub) > len(string):
            return 0
        if len(sub) == 1:
            return string.count(sub)
        raw = self.count_find(sub, string[1:]) % 10000
        if sub[0] != string[0]:
            return raw
        return (raw + self.count_find(sub[1:], string[1:])) % 10000
    
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