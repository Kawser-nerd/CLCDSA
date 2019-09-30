from sys import stdin

def summarize(seq):
    i = 0
    while (2 * i + 3 < len(seq)):
        if seq[2 * i + 1] == seq[2 * i +3]:
            seq = seq[:2*i] + [seq[2 * i] + seq[2 * i + 2]] + seq[2 * i + 3:]
        else:
            i += 1
    return seq

for cn in xrange(1,1+int(stdin.readline())):
    [N,M] = [int(z) for z in stdin.readline().split()]
    A = [int(z) for z in stdin.readline().split()]
    B = [int(z) for z in stdin.readline().split()]
    A = summarize(A)
    B = summarize(B)
    N = len(A) / 2
    M = len(B) / 2
    A = [A[2*i:2*i+2] for i in xrange(N)]
    B = [B[2*i:2*i+2] for i in xrange(M)]
    W = [[0 for i in xrange(M+1)] for j in xrange(N+1)]
    for i in xrange(N):
        for j in xrange(M):
            W[i+1][j+1] = max(W[i+1][j], W[i][j+1])
            if A[i][1] == B[j][1]:
                ps = [[z,A[z][0]] for z in xrange(i,-1,-1) if A[z][1] == A[i][1]]
                qs = [[z,B[z][0]] for z in xrange(j,-1,-1) if B[z][1] == B[j][1]]
                for iz in xrange(1,len(ps)):
                    ps[iz][1] += ps[iz-1][1]
                for iz in xrange(1,len(qs)):
                    qs[iz][1] += qs[iz-1][1]
                for k in ps:
                    for l in qs:
                        W[i+1][j+1] = max(W[i+1][j+1],W[k[0]][l[0]]+min(k[1],l[1]))
    print "Case #%d: %d" % (cn, W[-1][-1])
