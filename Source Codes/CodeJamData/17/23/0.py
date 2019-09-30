from sys import stdin

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

def solve(N,D):
    for j in xrange(N):
        for i in xrange(N):
            for k in xrange(N):
                D[i][k] = min(D[i][k], D[i][j]+D[j][k])

infinity = 10**20

(T,) = getInts()
for cn in xrange(1,1+T):
    (N,Q) = getInts()
    E = []
    S = []
    for i in xrange(N):
        (Ei, Si) = getInts()
        E.append(Ei)
        S.append(Si)
    D = [getInts() for i in xrange(N)]
    D = [[float(infinity if k == -1 else k) for k in row] for row in D]
    solve(N,D)
    D = [[infinity if k > E[i] else float(k)/S[i] for k in D[i]] for i in xrange(N)]
    solve(N,D)
    questions = [getInts() for z in xrange(Q)]
    answers = [D[i-1][j-1] for (i,j) in questions]
    print "Case #{}: {}".format(cn, " ".join(str(answer) for answer in answers))
    
