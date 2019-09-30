#!/usr/bin/env python
import sys
from math import *
from scipy.optimize import *

def read(n):
    r = []
    for i in xrange(n):
        r.append(map(int, sys.stdin.readline().split()))
    return r

def solve():
    W, L, U, G = map(int, sys.stdin.readline().split())
    low = read(L)
    up  = read(U)
    # print low, up

    xx = list(set(zip(*low)[0] + zip(*up)[0]))
    xx.sort()
    # print xx


    def interpolate(poly):
        ret = [0] * len(xx)
        i_ = 0
        x_, y_ = poly[0]
        for x,y in poly[1:]:
            i = xx.index(x)
            for j in range(i_,i+1):
                ret[j] = y_ + (xx[j] - x_) * (y-y_) / float(x-x_)
            i_, x_, y_ = i, x, y
        return ret

    ll = interpolate(low)
    uu = interpolate(up)
    uu = [u-l for u,l in zip(uu,ll)]

    def area(i):
        return (xx[i+1]-xx[i])*.5*(uu[i]+uu[i+1])

    def cut(i, a):
        m = (uu[i+1]-uu[i]) / float(xx[i+1]-xx[i])
        b = uu[i]
        if (abs(m) < 1e-20):
            x = a / b
        else:
            x = - b + sqrt(b*b + 2 * m * a)
            x /= m
        # print "cut ", i, a, m, b, x
        x = fsolve(lambda x: b*x + .5*m*x*x - a, x)[0]
        return x

    # print xx
    # print uu
    # print area(0)
    a = sum([area(i) for i in range(len(xx)-1)]) / G
    # print "##", a


        
    np = 0
    used = 0.
    for i in range(len(xx)-1):
        # print "# ", i, used, area(i)
        while area(i) - used > a:
            x = cut(i, used+a)
            print xx[i] + x
            np += 1
            if np==G-1:
                return
            used += a
        used = used - area(i)

            
    



if __name__=="__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        print "Case #{}:".format(t+1)
        solve()

    
