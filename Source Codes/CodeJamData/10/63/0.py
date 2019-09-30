import getopt, sys

x2 = [[[a,b] for a in range(41) for b in range(21)] for c in range(21)]
for i in range(20):
    x2[i+1] = [z for z in x2[i+1] if [z[0]-1,z[1]] in x2[i] and (([z[0]-2,z[1]] in x2[i]) or ([z[0],z[1]-1] in x2[i]))]

x2 = [min([sum(z) for z in k]) for k in x2]

x3 = [[[[[True] for a in range(21)] for b in range(41)] for c in range(61)] for d in range(21)]

def ok(i,j,k,l):
    return (j >= 0) and (k >= 0) and (l >= 0) and x3[i][j][k][l]

for i in range(20):
    print i
    for j in range(61):
        for k in range(41):
            for l in range(21):
                x3[i+1][j][k][l] = ok(i,j-1,k,l) and (ok(i,j-2,k,l) or ok(i,j,k-1,l)) and (ok(i,j-3,k,l) or ok(i,j-1,k-1,l) or ok(i,j,k,l-1))

x3 = [[[j,k,l] for j in range(61) for k in range(41) for l in range(21) if z[j][k][l]] for z in x3]
x3 = [min([sum(z) for z in k]) for k in x3]


x1 = [k for k in range(21)]


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

class ProblemC:
    def __init__(self, fileobject):
        [self.K, self.C] = [int(z) for z in fileobject.readline().split()]
        print self.C, self.K

    def solution(self):
        return str([[],x1,x2,x3][self.C][self.K])

def usage():
    print "probC.py    runs on test data"
    print "probC.py -t runs on test data"
    print "probC.py -s runs on small data"
    print "probC.py -l runs on large data"
    print "probC.py -h prints this message"

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
    infile = "c:\\documents and settings\\codejam\\linguo\\/problemC/C-" + type + ".in"
    outfile = "c:\\documents and settings\\codejam\\linguo\\/problemC/C-" + type + ".out"
    SolveCodeJam(infile, ProblemC, outfile)

if __name__ == "__main__":
    main()

