inputFileName = "D-small-attempt0.in"
outputFileName = "D-small-attempt0.out"

Debug = False

class Permutation:
    def __init__(self, justalist):
        self._data = justalist[:]
        self._sofar = []

    def __iter__(self):
        return self.next()

    def next(self):
        for i in xrange(0, len(self._data)):
            if self._data[i] not in self._sofar:
                self._sofar.append(self._data[i])
                if len(self._sofar) == len(self._data):
                    yield self._sofar[:]
                else:
                    for v in self.next():
                        yield v
                self._sofar.pop()

import sys

def dprint(s) :
    if Debug :
        sys.stderr.write(s)

def permute(s, p) :
    s2 = ""
    i = 0
    while i < len(s) :
        for j in p :
            s2 += s[i+j]
        i += len(p)
    return s2

def runLength(s, p) :
    s2 = permute(s, p)
    length = 0
    last = 'A'
    for c in s2:
        if c != last :
            length += 1
        last = c
    return length
        
def solve(s, k) :
    l = [runLength(s, p) for p in Permutation(range(0, k))]
    return min(l)
    
def solveCase(fileIn):
    k = int(fileIn.readline())
    s = fileIn.readline().strip()
    return solve(s, k)

def main():
    import sys
    fileIn = open(inputFileName)
    if outputFileName == "stdout":
        fileOut = sys.stdout
    else:
        fileOut = open(outputFileName, "w")
    N = int(fileIn.readline())
    dprint("%d cases\n" % N)
    for i in range(N):
        dprint("Entering case %d\n" % (i+1))
        ans = solveCase(fileIn)
        dprint("Answer : %s\n" % ans)
        fileOut.write("Case #%d: " % (i+1))
        fileOut.write("%s\n" % ans)
    fileIn.close()
    if outputFileName != "stdout":
        fileOut.close()

if __name__== "__main__":
    main()
