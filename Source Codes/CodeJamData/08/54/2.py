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

def f(c,d):
    # Return the number of ways of getting from (0,0) to (c,d)
    if (c + d) % 3 != 0:
        return 0
    if (c > 2*d):
        return 0
    if (d > 2*c):
        return 0
    a = (2*d - c) / 3
    b = (2*c - d) / 3
    x = 1
    for y in range(a):
        x *= (a+b-y)
        x /= (y+1)
    return x

class ProblemD:
    def __init__(self, fileobject):
	## Read from fileobject into local variables with lines like
	## self.T = int(fileobject.readline())
	##  or
	## self.nums=fileobject.readline().split(' ')
        params = [int(x) for x in fileobject.readline().split(' ')]
        self.H = params[0]
        self.W = params[1]
        self.R = params[2]
        self.Rocks = [[int(y) for y in fileobject.readline().split(' ')] for z in range(self.R)]

    def solution(self):
	## Use above local variables to return string
	## for example: return str(x) + ' ' + str(y)
	## parse floats with eg. "%1.6f" % f
        rox = self.Rocks;
        rox.sort();
        ans = 0
        j = [[0 for k in range(self.W)] for z in range(self.H)]
        j[0][0] = 1
        for i in range(self.H):
            for z in range(self.W):
                if [i+1,z+1] in rox:
                    dummy = -1
                else:
                    if (i >= 2 and z >= 1):
                        j[i][z] += j[i-2][z-1]
                    if (i >= 1 and z >= 2):
                        j[i][z] += j[i-1][z-2]
        for i in range(1 << self.R):
            incRox = [rox[y] for y in filter(lambda x: (i >> x) & 1 == 1, range(self.R))]
            incRox.insert(0,[1,1])
            incRox.append([self.H,self.W])
            localans = reduce(lambda x,y:x*y, [f(incRox[y+1][0]-incRox[y][0],incRox[y+1][1]-incRox[y][1]) for y in range(len(incRox)-1)])
            if (len(incRox) & 1 == 1):
                ans -= localans
            else:
                ans += localans
        if ans != j[self.H-1][self.W-1]:
            print [ans,j[self.H-1][self.W-1]];
        return str(ans % 10007)
        
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
    infile = "d:\\codejam\\round3\\ProblemD\\D-" + type + ".in"
    outfile = "d:\\codejam\\round3\\ProblemD\\D-" + type + ".out"
    CodeJamSolver(infile, ProblemD, outfile)

if __name__ == "__main__":
    main()
