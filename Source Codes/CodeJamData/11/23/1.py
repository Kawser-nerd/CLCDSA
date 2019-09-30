#!/usr/bin/env python

import sys

def verify(a, b):
    cc = len(set(b))
    for x in a:
        if len(set([b[i] for i in x])) != cc:
            return False
    return True



def foo(ifile):
    N, M = [int(x) for x in ifile.readline().split()]
    U = [int(x) for x in ifile.readline().split()]
    V = [int(x) for x in ifile.readline().split()]

    n = len(U)
    a = [range(1, N+1)]
    for i in range(n):
        u = U[i]
        v = V[i]
        for x in a:
            if u in x and v in x:
                idx1 = x.index(u)
                idx2 = x.index(v)
                if idx1 > idx2:
                    idx1, idx2 = idx2, idx1
                t1 = (x+x)[idx1:idx2+1]
                t2 = (x+x)[idx2:idx1+len(x)+1]
                a.remove(x)
                a += [t1, t2]
                break
    a = [[y-1 for y in x] for x in a]
    t2 = min([len(x) for x in a])
    res = 0
    res2 = None
    for i in range(t2**N):
        b = [0] * N
        for j in range(N):
            b[N-1-j] = i % t2
            i //= t2
        if len(set(b)) <= res:
            continue
        tmp = verify(a, b)
        if tmp:
            res = len(set(b))
            res2 = b
            if len(set(b)) == t2:
                break
    return "%s\n" % res + " ".join([str(x+1) for x in res2])





def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

