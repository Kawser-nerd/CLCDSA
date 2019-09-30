import getopt, sys
from math import sqrt

bigrec = 0
P = [0] * 10000
R = [0] * 10000

def clear():
    global P
    global R
    P = range(10001)
    R = [0] * 10001

def locate(i):
    global P
    if (P[i] == i):
        return i
    P[i] = locate(P[i])
    return P[i]

def combine(i, j):
    global P, R
    i = locate(i)
    j = locate(j)
    if (i == j):
        return False
    if (R[i] < R[j]):
        P[i] = j
    else:
        P[j] = i
        if (R[i] == R[j]):
            R[i] += 1
    return True

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
        [self.R, self.C] = [int(z) for z in fileobject.readline().split()]
        self.grid = [fileobject.readline().strip() for k in xrange(self.R)]

    def solution(self):
        dest0 = [-1] * (self.R * self.C)
        dest1 = [-1] * (self.R * self.C)
        for k in xrange(self.R):
            for l in xrange(self.C):
                g = self.grid[k][l]
                if (g == "|"):
                    k1 = (k + 1) % self.R
                    l1 = l
                    k2 = (k - 1) % self.R
                    l2 = l
                if (g == "-"):
                    k1 = k
                    l1 = (l + 1) % self.C
                    k2 = k
                    l2 = (l - 1) % self.C
                if (g == "\\"):
                    k1 = (k + 1) % self.R
                    l1 = (l + 1) % self.C
                    k2 = (k - 1) % self.R
                    l2 = (l - 1) % self.C
                if (g == "/"):
                    k1 = (k + 1) % self.R
                    l1 = (l - 1) % self.C
                    k2 = (k - 1) % self.R
                    l2 = (l + 1) % self.C
                dest0[k * self.C + l] = k1 * self.C + l1
                dest1[k * self.C + l] = k2 * self.C + l2
        N = self.R * self.C
        prevs = [[] for z in xrange(N)]
        for i in xrange(N):
            prevs[dest0[i]] += [[i, 0]]
            prevs[dest1[i]] += [[i, 1]]
        q = []
        for w in xrange(N):
            if len(prevs[w]) == 0: 
                return "0"
            if len(prevs[w]) == 1:
                q += [w]
        qat = 0
        qlen = len(q)
        while (qat < qlen):
            w = q[qat]
            [i, j] = prevs[w][0]
            prevs[w] = []
            if (j == 0):
                v = dest1[i]
            else:
                v = dest0[i]
            if [i, 1-j] not in prevs[v]:
                return "0"
            prevs[v] = [z for z in prevs[v] if z != [i, 1-j]]
            if len(prevs[v]) == 0:
                return "0"
            if len(prevs[v]) == 1:
                q += [v]
                qlen += 1
            qat += 1
        print prevs
        clear()
        ans = 1
        for w in prevs:
            if len(w) == 0:
                dummy = 17
            elif len(w) == 2:
                if not combine(w[0][0], w[1][0]):
                    ans *= 2
        return str(ans % 1000003)

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
    infile =  "/Users/Luke/gcj/R3/C/C-" + type + ".in"
    outfile = "/Users/Luke/gcj/R3/C/C-" + type + ".out"
    SolveCodeJam(infile, ProblemC, outfile)

if __name__ == "__main__":
    main()

