#!/usr/bin/env python
import sys

def read_n(a):
    n = int(a[0])
    return a[1:n+1], a[n+1:]

def solve():
    data = sys.stdin.readline.split()
    foo, data = read_n(data)


def solve():
    X, S, R, t, N = map(int, sys.stdin.readline().split())
    a = []
    for i in range(N):
        B,E,w = map(int, sys.stdin.readline().split())
        X -= E-B
        a.append([w, E-B])
    a.append([0,X])
    a.sort()
    # print a

    ret = 0.
    for w,d in a:
        rt = float(d) / (w+R)
        if rt <= t:
            t -= rt
            ret += rt
        else:
            d = float(d) - t * (w+R)
            ret += t
            t = 0.

            st = d / (w+S)
            ret += st
    return ret




if __name__=="__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        print "Case #{}: {}".format(t+1, solve())

    
