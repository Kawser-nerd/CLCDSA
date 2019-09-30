#!/usr/bin/env python

fin = open("3.in", "r")
fout = open("3.out", "w")

epsilon = 0.00000000001

T = int(fin.readline())
for t in range(T):
    print str(t+1)
    N, K = map(int, fin.readline().split())
    # only solve case K = N
    U = float(fin.readline())
    P = map(float, fin.readline().split())
    P.sort()
    P.append(1.0)

    while U > epsilon: # improve the smallest probability until it equals second smallest or U = 0
        # figure out j where all the first j probabilities are equal
        j = 0
        while j < len(P):
            if P[j] > P[0] + epsilon:
                break
            j += 1
        if j == len(P):
            break

        step = min(U / j, P[j] - P[0])
        U -= step * j
        for i in range(j):
            P[i] += step

    print P
    ans = 1.0
    for p in P:
        ans *= p
    if ans > 1.0:
        ans = 1.0
    ans = "{0:.6f}".format(ans)
    fout.write("Case #" + str(t+1) + ": " + ans + "\n")
