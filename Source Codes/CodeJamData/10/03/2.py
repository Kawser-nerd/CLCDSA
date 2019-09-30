#!/usr/bin/python

import sys, re, string, math

def do_one_case(cnum):
    (R, k, N) = map(int, sys.stdin.readline().split())
    g = map(int, sys.stdin.readline().split())
    assert len(g)==N
    E = []
    T = []
    for i in range(N):
        gx = g[i:] + g[:i]
        sgx = gx
        for j in range(1,N):
            sgx[j] += sgx[j-1]
        sgx2 = [ x for x in sgx if x<=k ]
        E.append(sgx2[-1])
        T.append((i + len(sgx2)) % N)
    EE = 0
    p = 0
    while R>0:
        if R&1:
            EE += E[p]
            p = T[p]
        E = [ E[i] + E[T[i]] for i in range(N) ]
        T = [ T[T[i]] for i in range(N) ]
        R /= 2
    print "Case #%d: %d" % (cnum, EE)
    


def main():
    N = int(sys.stdin.readline().strip())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
