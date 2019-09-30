import heapq
import sys
import itertools
from sets import Set
from blist import blist

class Case:
    def __init__(self, s, caseNum):
        self.caseNum = caseNum
        self.chars = tuple([x for x in s.read()])

    def solve(self):
        raw_chars = blist(self.chars)
        sorted = blist(raw_chars[:])
        sorted.sort()
        sorted.reverse()
#        print list(self.chars)
#        print sorted
        if list(self.chars) == sorted:
#            print "MATCH"
            raw_chars = blist(['0']) + raw_chars
        for i in xrange(len(raw_chars) - 1, 0, -1):
            if raw_chars[i-1] < raw_chars[i]:
                result = raw_chars[:i-1]
                smallest_bigger = 'A'
                smallest_bigger_index = -1
                for x in xrange(i, len(raw_chars)):
                    if raw_chars[x] > raw_chars[i - 1] and raw_chars[x] < smallest_bigger:
                        smallest_bigger = raw_chars[x]
                        smallest_bigger_index = x
                del raw_chars[smallest_bigger_index]
                result.append(smallest_bigger)
                remainder = raw_chars[i - 1:]
                remainder.sort()
                result = result + remainder
                return "".join(result)               
   
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
    
def read_header(s):
    numCases = int(s.read())
    return numCases

def run():
    import sys
    f = file(sys.argv[1])
    s = Contents(f)
    numCases = read_header(s)
    
    for caseNum in range(numCases):
        case = Case(s, caseNum)
        print "Case #%d: %s" % (caseNum + 1, case.solve())
        sys.stdout.flush()
        
if __name__ == "__main__":
    run()