#!/usr/bin/python

import sys, re, string

inf1 = 333222333444

def crossns(t, swt):
    (S, W, T) = swt
    C = S+W
    tx = (t-T) % C
    assert tx>=0
    if tx<S:
        #print t, swt, C, tx, 1, t+1
        return t+1
    else:
        #print t, swt, C, tx, 1+C-tx, t+1+C-tx
        return t+1+(C-tx)

def crossew(t, swt):
    (S, W, T) = swt
    return crossns(t, (W, S, T+S))

def do_one_case(cnum):
    (N, M) = map(int, sys.stdin.readline().split())
    swt = []
    for i in range(N):
        v = map(int, sys.stdin.readline().split())
        assert len(v)==3*M
        swt.append([(s,w,(t%(s+w))-(s+w)) for (s,w,t) in zip(v[0::3], v[1::3], v[2::3])])

    inf0 = 222333444555
    t = [ (2*M+2)*[inf0] for i in range(2*N+2) ];
    t[2*N][1] = 0;

    sum1=sum(map(sum,t))
    sum0 = sum1+1
    while sum1<sum0:
        sum0 = sum1
        #print t
        for i in range(N):
            for j in range(M):
                t[2*i+1][2*j+1] = min(t[2*i+1][2*j+1], 
                        2 + t[2*i][2*j+1],
                        2 + t[2*i+1][2*j],
                        crossns(t[2*i+2][2*j+1], swt[i][j]),
                        crossew(t[2*i+1][2*j+2], swt[i][j]))
                t[2*i+1][2*j+2] = min(t[2*i+1][2*j+2], 
                        2 + t[2*i][2*j+2],
                        2 + t[2*i+1][2*j+3],
                        crossns(t[2*i+2][2*j+2], swt[i][j]),
                        crossew(t[2*i+1][2*j+1], swt[i][j]))
                t[2*i+2][2*j+1] = min(t[2*i+2][2*j+1], 
                        2 + t[2*i+3][2*j+1],
                        2 + t[2*i+2][2*j],
                        crossns(t[2*i+1][2*j+1], swt[i][j]),
                        crossew(t[2*i+2][2*j+2], swt[i][j]))
                t[2*i+2][2*j+2] = min(t[2*i+2][2*j+2], 
                        2 + t[2*i+3][2*j+2],
                        2 + t[2*i+2][2*j+3],
                        crossns(t[2*i+1][2*j+2], swt[i][j]),
                        crossew(t[2*i+2][2*j+1], swt[i][j]))
        sum1 = sum(map(sum,t))
    print "Case #%d: %d" % (cnum, t[1][2*M])
    #print swt
    #print t
                



def main():
    N = int(sys.stdin.readline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
