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

class ProblemA:
    def __init__(self, fileobject):
	## Read from fileobject into local variables with lines like
	## self.T = int(fileobject.readline())
	##  or
	## self.nums=fileobject.readline().split(' ')
	self.en = int(fileobject.readline())
        self.numsX = map(lambda x: int(x), fileobject.readline().split(' '))
        self.numsY = map(lambda x: int(x), fileobject.readline().split(' '))
 
    def solution(self):
	## Use above local variables to return string
	## for example: return str(x) + ' ' + str(y)
	## parse floats with eg. "%1.6f" % f
        total = 0
        self.numsX.sort()
        self.numsY.sort()
        for i in range(self.en):
            x = self.numsX [i]
            y = self.numsY [self.en-(i+1)]
            total += x * y
        return str(total)

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
    infile = "d:\\codejam\\round1\\problema\\a-" + type + ".in"
    outfile = "d:\\codejam\\round1\\problema\\a-" + type + ".out"
    CodeJamSolver(infile, ProblemA, outfile)

if __name__ == "__main__":
    main()
