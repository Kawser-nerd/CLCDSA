#!/usr/bin/python


import sys
import math
import numpy as np
import time
#import multiprocessing

def readline():
    return sys.stdin.readline().strip().split()

def readints():
    return [int(x) for x in readline()]

# print 14
# for i in range(14):
#     x = min(3000, 300 * (i+1))
#     print x
#     for i in range(x):
#         print np.random.randint(0,200000),np.random.randint(0,200000)
# exit()

tstart = time.clock()



# NOTE: apparently need to make sure this stuff is seperated
if __name__ == '__main__':
    T, = readints()
    for testcase in range(T):
        N,V,X = readline()
        N=int(N)
        V=float(V)
        X=float(X)  # target temp
        R=[]   # source rates
        T=[]   #source temps
        ttt = []
        for idx in range(N):
            r,t = readline()
            r=float(r)
            t=float(t)
            ttt.append((t,r))

        ttt.sort()
        R = [r for t,r in ttt]
        T = [t for t,r in ttt]

        def solve():
            if min(T) > X or max(T) < X:
                return 'IMPOSSIBLE'

            if N == 1:
                return V / R[0]

            global heat, rate
            heat = 0.
            rate = 0.
            for r,t in zip(R,T):
                heat += r*t
                rate += r


            def find_mid(R1,R2,T1,heat2, X):
                #print "find R1,R2=", R1,R2
                # given 100% of source 2 and Y% of source 1, target X, find rate X

                T2 = heat2 / R2
                if abs(T1 - T2) < 1e-9:
                #if T1 == T2:
                    return R1+R2

                fr = (heat2 / X - R2 ) / (R1 - R1 * T1 / X)
                X2 = (fr * R1 * T1 + heat2) / (fr * R1 + R2)
                rate = R1 * fr + R2
                #print "find_mid X = %f fr= %f  actualX = %f  rate=%f" % (X, fr, X2, rate)
                return rate



            def remove_source(which):
                global heat, rate, R, T
                newR = R[:]
                newT = T[:]
                del newR[which]
                del newT[which]
                #heat2 = heat - R[which] * T[which]
                #rate2 = rate - R[which]
                rate2 = sum(newR)
                heat2 = 0.
                for r,t in zip(newR,newT):
                    heat2 += r*t

                temp2 = heat2/rate2
                if ((temp < X) and (temp2 <= X)) or ((temp > X) and (temp2 >= X)):
                    #print "remove completely R", R[which], "T", T[which]
                    # remove completely
                    heat = heat2
                    rate = rate2
                    R = newR
                    T = newT
                    return None
                else:
                    #print "solution: reduce R", R[which], "T", T[which]
                    srate = find_mid(R[which], rate2, T[which], heat2, X)
                    return "%.9f" % (V/srate)


            #print "R", R, "T", T, "X", X, "V", V

            while True:
                temp = heat/rate
                #print "heat", heat, "rate", rate, "temp", temp, "sources left:", len(R)
                if abs(temp - X) < 1e-8:
                #if heat == X * rate:
                    return "%.9f" % (V/rate)
                if temp < X:
                    # reduce coldest remaining
                    ret = remove_source(0)
                    if ret is not None:
                        return ret
                else:
                    ret = remove_source(len(R) - 1)
                    if ret is not None:
                        return ret
                if len(R) == 0:
                    assert False


        print "Case #%d: %s" % ( testcase+1, solve())



#print "done in ",  time.clock() - tstart
