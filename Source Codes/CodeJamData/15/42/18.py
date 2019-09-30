import sys
from operator import itemgetter

def run(N,V,X,pipes):
    # X is temp
    # V is volume
    # each pipe is (flow, temp), (r,c)
    for i in xrange(N):
        pipes[i][1] = pipes[i][1] - X
    pipes.sort(key = itemgetter(1))
    if pipes[0][1] > 0 or pipes[N-1][1] < 0:
        return 'IMPOSSIBLE'
    cutoff = 0
    while pipes[cutoff][1] < 0:
        cutoff += 1

    flow = 0
    poss = pipes[cutoff:]
    negs = pipes[:cutoff]
    poss.reverse()

    while poss and poss[-1][1] == 0:
        flow += poss[-1][0]
        del poss[-1]

    while poss and negs:
        topp = poss[-1]
        topn = negs[-1]
        totp = topp[0]*topp[1]
        totn = -topn[0]*topn[1]
        added = min(totp, totn)
        flowp = added/topp[1]
        flown = - added/topn[1]
        flow +=  flowp + flown
        if totp > totn:
            del negs[-1]
            poss[-1] = (poss[-1][0]-flowp, poss[-1][1])
        if totp < totn:
            del poss[-1]
            negs[-1] = (negs[-1][0]-flown, negs[-1][1])
        if totp == totn:
            del negs[-1]
            del poss[-1]

    return '%.9f' % (V / flow)

fin = open(sys.argv[1])

T = int(fin.readline().strip())
for i in range(1,T+1):
    aa,bb,cc = fin.readline().strip().split()
    N = int(aa)
    V = float(bb)
    X = float(cc)
    pipes = []
    for iii in range(N):
        pipes.append([float(x) for x in fin.readline().strip().split()])
    ans = run(N,V,X,pipes)
    print('Case #%d: %s' % (i, ans))
