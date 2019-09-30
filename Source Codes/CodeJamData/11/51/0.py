import getopt, sys
from math import sqrt

bigrec = 0

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
        [self.W, self.L, self.U, self.G] = [int(z) for z in fileobject.readline().split()]
        self.lower = [[int(z) for z in fileobject.readline().split()] for k in xrange(self.L)]
        self.upper = [[int(z) for z in fileobject.readline().split()] for k in xrange(self.U)]

    def solution(self):
        global bigrec
        xs = list(set([z[0] for z in self.lower + self.upper]))
        xs.sort()
        xs = [a + 0.0 for a in xs]
        N = len(xs)
        ly = [0] * N
        uy = [0] * N
        previ = 0
        ly[0] = self.lower[0][1] + 0.0
        for i in self.lower[1:]:
            j = xs.index(i[0])
            ly[j] = i[1] + 0.0
            for k in xrange(previ + 1, j):
                ly[k] = ly[previ] + ((xs[k] - xs[previ]) * (ly[j] - ly[previ])) / (xs[j] - xs[previ])
            previ = j
        previ = 0
        uy[0] = self.upper[0][1]
        for i in self.upper[1:]:
            j = xs.index(i[0])
            uy[j] = i[1] + 0.0
            for k in xrange(previ + 1, j):
                uy[k] = uy[previ] + ((xs[k] - xs[previ]) * (uy[j] - uy[previ])) / (xs[j] - xs[previ])
            previ = j
        dy = [uy[i] - ly[i] for i in xrange(N)]
        area = 0
        for i in xrange(1,N):
            area += (dy[i] + dy[i-1]) * (xs[i] - xs[i-1]) / 2
        arG = area / self.G
        splits = []
        cumul = 0
        for i in xrange(1,N):
            oldx = xs[i-1]
            oldy = dy[i-1]
            areaOfPiece = (dy[i] + dy[i-1]) * (xs[i] - xs[i-1]) / 2
            while cumul + areaOfPiece > arG:
                newArea = arG - cumul
                grad = (dy[i] - dy[i-1]) / (xs[i] - xs[i-1])
                l = dy[i-1]
                if (grad == 0):
                    t = newArea / l
                else:
                    t = (sqrt(2 * grad * newArea + l * l) - l) / grad
                if bigrec < abs(newArea - (l * t + grad * t * t / 2)):
                    bigrec = abs(newArea - (l * t + grad * t * t / 2))
                print newArea, l * t + grad * t * t / 2, bigrec
                # newArea = l * t + grad * t * t / 2
                # 2 * grad * newArea = grad * grad * t * t + 2 * grad * l * t
                # 2 * grad * newArea + l * l = (grad * t + l)
                splits += [xs[i-1] + t]
                cumul = 0
                dy[i-1] += grad * t
                xs[i-1] += t
                areaOfPiece -= newArea
            xs[i-1] = oldx
            dy[i-1] = oldy
            cumul += areaOfPiece
        if len(splits) > self.G - 1:
            if bigrec < abs(splits[-1] - xs[-1]):
                bigrec = abs(splits[-1] - xs[-1])
            print splits[-1], xs[-1], bigrec
            splits = splits[:(self.G - 1)]
        w = []
        print self.lower, self.upper
        print ly, uy
        print xs, dy, area, N
        for sp in splits:
            area = 0
            for i in xrange(1,N):
                if (xs[i] < sp):
                    area += (dy[i] + dy[i-1]) * (xs[i] - xs[i-1]) / 2
                else:
                    if (xs[i-1] < sp):
                        print "*"
                        y = dy[i-1] + ((dy[i] - dy[i-1]) * (sp - xs[i-1])) / (xs[i] - xs[i-1])
                        area += (dy[i-1] + y) * (sp - xs[i-1]) / 2
            w += [area / arG]
        if [int(z+0.000005) for z in w] != range(1,self.G):
            print "!!!!!"
            while (6 == 6):
                dummy = 17
        return "\n".join([""] + ["%.6f" % x for x in splits])

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
    infile =  "/Users/Luke/gcj/R3/A/A-" + type + ".in"
    outfile = "/Users/Luke/gcj/R3/A/A-" + type + ".out"
    SolveCodeJam(infile, ProblemA, outfile)

if __name__ == "__main__":
    main()

