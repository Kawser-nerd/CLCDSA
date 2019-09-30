import getopt, sys

def SolveCodeJam(infilename, problemclasstype, outfilename):
    print "Parsing " + infilename + " to " + outfilename
    infileobject = open(infilename,'r')
    outfileobject = open(outfilename, 'w')
    N = int(infileobject.readline())
    for i in xrange(1, N + 1):
        print 'Case #' + str(i) + ' of ' + str(N)
        problem = problemclasstype(infileobject)
        print ' read case'
        solution = problem.solution()
        print ' ' + solution
        outfileobject.write('Case #' + str(i) + ': ' + solution + '\n')
    infileobject.close()
    outfileobject.close()

class ProblemA:
    def __init__(self, fileobject):
        self.string = fileobject.readline().strip()
        self.dyn = {}
    def answer(self, i, j):
        while ((i + 1 < j) and (self.string[i] == self.string[i+1])):
            i += 1
        if (not (self.dyn.has_key(i))):
            self.dyn[i] = {}
        if (self.dyn[i].has_key(j)):
            return self.dyn[i][j]
        if (i >= j):
            return 0
        if (i + 1 == j):
            return 1
        rec = 1 + self.answer(i+1, j)
        for x in range(i+1, j):
            if (self.string[x] == self.string[i]):
                ansr = self.answer(i+1, x) + self.answer(x, j)
                rec = min(rec, ansr)
        self.dyn[i][j] = rec
        return rec
    def solution(self):
        return str(2*self.answer(0, len(self.string))+len(self.string))
        # requested = [False] * self.numGoogles
        # numSinceSwitch = 0
        # numSwitches = 0
        # for r in self.requests:
        #     if (not requested[r]):
        #         if (numSinceSwitch == self.numGoogles - 1):
        #             requested = [False] * self.numGoogles
        #             numSinceSwitch = 0
        #             numSwitches += 1
        #         requested[r] = True
        #         numSinceSwitch += 1
        # return str(numSwitches)

def usage():
    print "probA.py    runs on test data"
    print "probA.py -t runs on test data"
    print "probA.py -s runs on small data"
    print "probA.py -l runs on large data"
    print "probA.py -h prints this message"

def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "hstl", ["help", "small", "test", "large"])
    except getopt.GetoptError, err:
        print str(err)
        usage()
        sys.exit(2);
    type = "test"
    for o, a in opts:
        if o in ("-h", "--help"):
            usage()
            sys.exit()
        elif o in ("-s", "--small"):
            type = "small"
        elif o in ("-l", "--large"):
            type = "large"
    infile = "c:\\documents and settings\\codejam\\linguo\\/problemA/A-" + type + ".in"
    outfile = "c:\\documents and settings\\codejam\\linguo\\/problemA/A-" + type + ".out"
    SolveCodeJam(infile, ProblemA, outfile)

if __name__ == "__main__":
    main()

