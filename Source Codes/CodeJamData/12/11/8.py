from sys import stdin
T = int( stdin.readline() )
for t in range(1,T+1):
    A, B = [ int(x) for x in stdin.readline().split() ]
    P = [ float(x) for x in stdin.readline().split() ]
    best = B+2
    prob_corr = 1.0
    for bs in range(A,-1,-1):
        curr = prob_corr * (2*bs+B-A+1) + (1-prob_corr) * (2*bs+B-A+1+B+1)
        best = min( best, curr )
        if bs>0: prob_corr *= P[A-bs]
    print "Case #%d: %.13f" % (t,best)
