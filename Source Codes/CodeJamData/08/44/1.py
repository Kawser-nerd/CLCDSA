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

class ProblemD:
    def __init__(self, fileobject):
	## Read from fileobject into local variables with lines like
	## self.T = int(fileobject.readline())
	##  or
	## self.nums=fileobject.readline().split(' ')
        self.k = int(fileobject.readline())
        self.S = fileobject.readline().rstrip('\n')
 
    def solution(self):
	## Use above local variables to return string
	## for example: return str(x) + ' ' + str(y)
	## parse floats with eg. "%1.6f" % f
        x = [[0 for a in range(self.k)] for b in range(self.k)]
        d = [[0 for a in range(self.k)] for b in range(self.k)]
        for i in range(len(self.S)/self.k):
            for j in range(self.k):
                for t in range(j):
                    if (self.S[i*self.k+t] == self.S[i*self.k+j]):
                        x[t][j] += 1
                        x[j][t] += 1
                for t in range(self.k):
                    if ((i+1) * self.k < len(self.S)
                        and self.S[i*self.k+t] == self.S[(i+1)*self.k+j]):
                        d[t][j] += 1
        rec = 0
        u = [v for v in range(self.k)]
        done = 0
        while (done != 1):
            print u
            sc = d[u[self.k-1]][u[0]]
            for t in range(self.k-1):
                sc += x[u[t]][u[t+1]]
            if sc > rec:
                rec = sc;
            z = self.k-2
            while (z >= 0 and u[z] > u[z+1]):
                z -= 1
            if (z == -1):
                done = 1
            else:
                y = z+1
                while (y < self.k and u[y] > u[z]):
                    y += 1
                y -= 1
                p = u[y]
                u[y] = u[z]
                u[z] = p
                z = z+1
                y = self.k-1
                while (z < y):
                    p = u[y]
                    u[y] = u[z]
                    u[z] = p
                    y -= 1
                    z += 1
        return str(len(self.S)-rec)

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
    infile = "d:\\codejam\\round2\\ProblemD\\D-" + type + ".in"
    outfile = "d:\\codejam\\round2\\ProblemD\\D-" + type + ".out"
    CodeJamSolver(infile, ProblemD, outfile)

if __name__ == "__main__":
    main()
