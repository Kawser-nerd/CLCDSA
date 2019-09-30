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

class ProblemD:
    def __init__(self, fileobject):
        self.N = int(fileobject.readline())
        self.xs = [int(z) for z in fileobject.readline().split()]
        self.xs.sort()
        self.F = int(fileobject.readline())
        # self.numGoogles = int(fileobject.readline())
        # googles = [fileobject.readline().strip() 
        #            for i in xrange(int(self.numGoogles))]
        # self.requests = [googles.index(fileobject.readline().strip())
        #                  for i in xrange(int(fileobject.readline()))]

    def solution(self):
        ds = [self.xs[i+1]-self.xs[i] for i in xrange(self.N-1)]
        sofars = [[2*ds[0],2]]
        for i in xrange(1,len(ds)):
            sofars = [[a[0]+b*ds[i],b] for a in sofars for b in [a[1]-2,a[1],a[1]+2] if b > 0] 
            print len(sofars)
        sofars = [z[0] for z in sofars if z[1] == 2 and z[0] <= self.F]
        if len(sofars) == 0:
            return "NO SOLUTION"
        return str(max(sofars))
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
    print "probD.py    runs on test data"
    print "probD.py -t runs on test data"
    print "probD.py -s runs on small data"
    print "probD.py -l runs on large data"
    print "probD.py -h prints this message"

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
    infile = "c:\\documents and settings\\codejam\\linguo\\/problemD/D-" + type + ".in"
    outfile = "c:\\documents and settings\\codejam\\linguo\\/problemD/D-" + type + ".out"
    SolveCodeJam(infile, ProblemD, outfile)

if __name__ == "__main__":
    main()

