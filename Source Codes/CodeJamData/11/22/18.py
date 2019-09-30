#!/usr/bin/python

import sys, re, string, math

ssr = sys.stdin.readline
ssw = sys.stdout.write

D = -99

def comb(L, x):
    # print D, L, x
    if not L:
        return [x]
    (p1,v1,t1) = L[-1]
    (p2,v2,t2) = x
    v3 = v1 + v2
    if (p2-p1) < 0.5*D*v3:
        m = 0.5*D*v3 - (p2-p1)
        if t1<t2:
            d = t2-t1
            mm = max(0, 0.5*(m-d))
            t3 = t2+mm
            p3 = p2 + mm - 0.5*D*v1
#            if m<d:
#                t3 = t2
#                p3 = p2 + 0.5*D*(v2-1) - 0.5*D*(v3-1)
#            else:
#                mm = 0.5*(m-d)
#                p2 += mm
#                t2 += mm
#                t3 = t2
#                p3 = p2 + 0.5*D*(v2-1) - 0.5*D*(v3-1)
        else:
            d = t1-t2
            mm = max(0, 0.5*(m-d))
            t3 = t1+mm
            p3 = p1 - mm + 0.5*D*v2
        L[-1] = (p3, v3, t3)
    else:
        L.append(x)
    # print L
    return L
    

def do_one_case(cnum):
    global D

    (C, D) = map(int, ssr().split())
    L = [];
    for i in range(C):
        (P,V) = map(int, ssr().split())
        t = 0.5*D*(V-1)
        L.append((1.0*P,V,t))
    n = C+1
    while len(L)<n:
        n = len(L)
        L = reduce(comb, L, [])
    t = max([t for (P,V,t) in L])
    print "Case #%d: %.14g" % (cnum, t)


def main():
    N = int(ssr().strip())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
