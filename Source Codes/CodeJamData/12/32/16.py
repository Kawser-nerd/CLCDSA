from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [float(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

def pad0(X):
    Y = {}
    for i in range(len(X)):
        Y[i] = X[i]
    Y[-1] = 0
    return Y

for k in range(T):
    
    print "Case #%d:" % (k+1)
    
    D, N, A = readlist()
    N = int(N); A = int(A);
    #~ print D, N, A
    
    X = []
    T = []
    for i in range(N):
        t,x = readlist()
        X.append(x)
        T.append(t)
    Accs = readlist()
    
    # avem grija ca masina cealalta sa se opreasca unde vrem noi
    for i in range(N):
        if X[i] > D:
            if i > 0:
                v = (X[i] - X[i-1]) / (T[i] - T[i-1])
                #~ print "viteza: ", v
                T[i] = T[i] - (X[i] - D) / v
            X[i] = D
            N = i+1
            break
    
    X = X[:N]
    T = T[:N]
    
    
    #~ X = pad0(X)
    #~ T = pad0(T)
    #~ print X, T
    
    for a in Accs:
        x0 = 0
        v0 = 0
        t = 0
        
        for i in range(1,N): # pe fiecare segment
            dt = T[i] - T[i-1]
            Xend = x0 + v0*dt + a*dt*dt/2
            Xother = X[i]
            Vother = (X[i] - X[i-1]) / (T[i] - T[i-1])
            #~ print Vother
            if Xend < Xother:
                x0 = Xend # yay, nu m-am ciocnit
                v0 = v0 + a*dt
                t = T[i]
                #~ print "nu m-am ciocnit"
            else:
                x0 = Xother

                # in cat timp pot sa parcurg dx?
                dx = X[i] - X[i-1]
                dtx1 = (-v0 + sqrt(v0**2 + 2*a*dx))/a
                dtx2 = -(v0 + sqrt(v0**2 + 2*a*dx))/a
                dtx = max(dtx1,dtx2)
    
                v0 = v0 + a*dtx
                #~ print "vother, vmy", Vother, v0
                t = T[i]
            #~ print i, x0, v0, t
    
        # sa vedem cat mai avem
        dt = 0
        if x0 < D:
            dx = D-x0
            #~ print "mai avem: ", dx, v0, t

            dt1 = (-v0 + sqrt(v0**2 + 2*a*dx))/a
            dt2 = -(v0 + sqrt(v0**2 + 2*a*dx))/a
            dt = max(dt1,dt2)
            #~ print dt1, dt2
        
        print t+dt
