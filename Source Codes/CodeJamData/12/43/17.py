#!/usr/bin/env python3

# Google Code Jam 2012, Round 2, Problem C: Mountain View
#
# Damn, it's late........

import fractions

f = fractions.Fraction

def rat(a, b):
    if v[a] == v[b]:
        return 0
    return f(v[b]-v[a], b-a)

cases = int(input())
for case in range(cases):
    N = int(input())
    x = list(int(s)-1 for s in input().split())

    possible = True
    for i, xi in enumerate(x):
        if xi > i+1:
            if max(x[i+1:xi]) > xi:
                possible = False
                break
    if not possible:
        print("Case #{}: {}".format(case + 1, "Impossible"))
        continue
 
    v = [1]*N
    cg = True
    while cg:
        cg = False
        for i, xi in enumerate(x):
            cl = True
            while cl:
                cl = False
                if xi-i > 1:
                    while rat(i,xi) <= max(rat(i,j) for j in range(i+1, xi)):
                        v[xi] += 1
                        cg = cl = True
                if N-xi > 1:
                    while rat(i,xi) < max(rat(i,j) for j in range(xi+1, N)):
                        v[xi] += 1
                        cg = cl = True
    print("Case #{}: {}".format(case + 1, " ".join(str(vi) for vi in v)))
