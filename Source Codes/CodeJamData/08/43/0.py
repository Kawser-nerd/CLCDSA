import getopt, sys
def CodeJamSolver(infilename, problemclasstype, outfilename):
    print "Parsing " + infilename + " to " + outfilename
    infileobject = open(infilename,'r')
    outfileobject = open(outfilename, 'w')
    N = int(infileobject.readline())
    for i in range(N):
	print 'Case #' + str(i+1)
	problem = problemclasstype(infileobject)
	solution = problem.solution()
	print solution
	outfileobject.write('Case #' + str(i+1) + ': ' + solution + '\n')
    infileobject.close()
    outfileobject.close()

class ProblemC:
    def __init__(self, fileobject):
	## Read from fileobject into local variables with lines like
	## self.T = int(fileobject.readline())
	##  or
	## self.nums=fileobject.readline().split(' ')
        self.N = int(fileobject.readline())
        self.xyzp = [[] for k in range(self.N)]
        for i in range(self.N):
            line = fileobject.readline()
            self.xyzp[i] = map(lambda x: int(x), line.split(' '))
 
    def solution(self):
	## Use above local variables to return string
	## for example: return str(x) + ' ' + str(y)
	## parse floats with eg. "%1.6f" % f
        upper = 0.0
        lower = 0.0
        for i in range(self.N):
            power = (0.0 + self.xyzp[i][0] + self.xyzp[i][1] + self.xyzp[i][2])
            power /= self.xyzp[i][3]
            if (power > upper):
                upper = power
        xyzp = self.xyzp
        pp = [+k[0]+k[1]+k[2] for k in xyzp]
        pm = [+k[0]+k[1]-k[2] for k in xyzp]
        mp = [+k[0]-k[1]+k[2] for k in xyzp]
        mm = [-k[0]+k[1]+k[2] for k in xyzp]
        pows = [k[3] for k in xyzp]
        while (upper > lower + 0.000001):
            T = (upper + lower) / 2
            ppx = [T*pows[i]+pp[i] for i in range(self.N)]
            pmx = [T*pows[i]+pm[i] for i in range(self.N)]
            mpx = [T*pows[i]+mp[i] for i in range(self.N)]
            mmx = [T*pows[i]+mm[i] for i in range(self.N)]
            ppn = [-T*pows[i]+pp[i] for i in range(self.N)]
            pmn = [-T*pows[i]+pm[i] for i in range(self.N)]
            mpn = [-T*pows[i]+mp[i] for i in range(self.N)]
            mmn = [-T*pows[i]+mm[i] for i in range(self.N)]
            if (
                (max(ppn)                   > min(ppx)) or
                (max(pmn)                   > min(pmx)) or
                (max(mpn)                   > min(mpx)) or
                (max(mmn)                   > min(mmx)) or
                (max(ppn)                   > min(pmx)+min(mpx)+min(mmx)) or
                (max(pmn)+max(mpn)+max(mmn) > min(ppx))):
                lower = T
            else:
                upper = T
        return "%1.6f" % lower

def usage():
    print "probA.py    runs on test data"
    print "probA.py -t runs on test data"
    print "probA.py -s runs on small data"
    print "probA.py -l runs on large data"
    print "probA.py -h prints this message"

def main():
    try:
	opts, args = getopt.getopt(sys.argv[1:], "hstl",
["help", "small", "test", "large"])
    except getopt.GetoptError, err:
	print str(error)
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
    infile = "d:\\codejam\\round2\\ProblemC\\C-" + type + ".in"
    outfile = "d:\\codejam\\round2\\ProblemC\\C-" + type + ".out"
    CodeJamSolver(infile, ProblemC, outfile)

if __name__ == "__main__":
    main()
