#!/usr/bin/env python
import sys
from numpy import *

def read_n(a):
    n = int(a[0])
    return a[1:n+1], a[n+1:]

def solve():
    data = sys.stdin.readline.split()
    foo, data = read_n(data)


def solve():
    R, C, D = map(int,sys.stdin.readline().split())
    data = []
    data.append([0]*(C+1))
    for r in range(R):
        data.append([0]+map(int, sys.stdin.readline().strip()))
    # print len(data)
    # print map(len,data)
    # print data
        
    R += 1
    C += 1
    dk = array(data)
    mi, mj = mgrid[0:R,0:C]
    di = dk*mi
    dj = dk*mj
    si = cumsum(cumsum(di, axis=1),axis=0)
    sj = cumsum(cumsum(dj, axis=1),axis=0)
    sk = cumsum(cumsum(dk, axis=1),axis=0)

    # print di, dj, si, sj

    ret = 0
    for i in xrange(1,R):
        for j in xrange(1,C):
            for s in xrange(3, min(R-i,C-j)+1):
                ii = i+s-1
                jj = j+s-1
                def mysum(xx, x):
                    return xx[ii][jj] - xx[ii][j-1] - xx[i-1][jj] + xx[i-1][j-1] \
                        - x[i][j] - x[i][jj] - x[ii][j] - x[ii][jj]
                    
                rk = mysum(sk, dk)
                ri = mysum(si, di)

                # if ri != (i + (s-1)/2.) * rk:
                if 2*ri != (2*i + (s-1)) * rk:
                    continue
                rj = mysum(sj, dj)
                if 2*rj != (2*j + (s-1)) * rk:
                    continue
                # print i, j, s 
                ret = max(ret,s)

    return ret if ret>0 else 'IMPOSSIBLE'
                
                



if __name__=="__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        print "Case #{}: {}".format(t+1, solve())

    
