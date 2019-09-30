import heapq
import sys
import itertools

l = 0
d = 0
words = []

class Case:
    def __init__(self, s, caseNum):
        self.caseNum = caseNum
        self.string = s.read()

    def solve(self):
        pos = 0
        index = 0
        words_clone = words[:]
        while pos < len(self.string):
            if self.string[pos] == '(':
                possible_letter_list = self.parse_possibles(pos)
                words_clone = filter(lambda x: x[index] in possible_letter_list, words_clone)
                pos = self.string.index(")", pos) + 1
                index += 1
            else:
                words_clone = filter(lambda x: x[index] == self.string[pos], words_clone)
                pos += 1
                index += 1
        return len(words_clone)

    def parse_possibles(self, pos):
        return [x for x in self.string[pos+1:self.string.index(")", pos)]]
    
    def __repr__(self):
        return "Problem A Case %d" % self.caseNum

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
    global l, d, words
    import sys
    f = file(sys.argv[1])
    s = Contents(f)
    
    l, d, numCases = map(int, s.read().split(" "))
    words = s.readList(d)    
    for caseNum in xrange(numCases):
        case = Case(s, caseNum)
        print "Case #%d: %s" % (caseNum + 1, case.solve())
        sys.stdout.flush()
        
if __name__ == "__main__":
    run()