#!/home/edgar/pypy/bin/pypy
debug=False

from sys import stdin, stdout
from numpy import *

T = int(stdin.readline())
for t in range(1,T+1):
    P, Q, N = [int(word) for word in stdin.readline().strip().split()]
    H, G = [], []
    for i in range(N):
        h, g = [int(word) for word in stdin.readline().strip().split()]
        H.append(h); G.append(g)
    H = array(H, dtype=int)
    G = array(G, dtype=int64)

    # time cost
    C = ((H-1)%Q)//P + 1
    # time advantage earned (-1 if taken)
    T = (H-1) // Q + 1

    MAX_TIME = T.sum()
    
    # represents time advantage -> max gold earned fctn
    GLD = zeros(MAX_TIME+1, dtype=int)

    if debug:
        print P, Q, N
        print H
        print G
        print C
        print T

    for i in range(N-1, -1, -1):
        GLD_new = 0*GLD
        for ta in range(MAX_TIME+1):
            ta_s = min(T[i]-C[i]-1+ta, MAX_TIME)
            ta_n = min(T[i]+ta, MAX_TIME)
            g = GLD[ta_n]
            if ta_s >= 0 and G[i] + GLD[ta_s] > g:
                g = G[i] + GLD[ta_s]
            GLD_new[ta] = g
        GLD = GLD_new
        if debug:
            print GLD

    print "Case #"+str(t)+":",GLD[1]
    stdout.flush()
