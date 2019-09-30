#!/usr/local/bin/python

pmax = 1000000
primeHash = {}
prime = []

for i in range(2, pmax):
    primeHash[i] = 1

for i in range(2, pmax):
    if primeHash.has_key(i):
        for j in range(2, pmax/i+1):
            if primeHash.has_key(i*j):
                del primeHash[i*j]

prime = primeHash.keys()

fp = open("B-small.in")

line = fp.readline()
n = int(line)

for i in xrange(n):
    grp = {}
    grpV = {}
    line = fp.readline()
    A, B, P = map(int, line.split(" "))
    for j in xrange(A, B+1):
        grp[j] = j
    for j in prime:
        if j < P:
            continue
        if j > B-A+1:
            break
        nA = A / j
        if A % j != 0:
            nA += 1
        nB = B / j
        if nA == nB:
            continue
        for k in xrange(nA, nB+1):
            x = k * j
            y = (k+1) * j
            if A <= x and x <= B and A <= y and y <= B:
               # print "group", x, y
               # getGrp x
               g = x
               while g != grp[g]:
                   g = grp[g]
               gx = g
               # getGrp y
               g = y
               while g != grp[g]:
                   g = grp[g]
               gy = g
               # print "gx, gy", gx, gy
               if gx != gy:
                   grp [gx] = gy
               # print "grp", grp
    for j in xrange(A, B+1):
        g = j
        while g != grp[g]:
            g = grp[g]
        gj = g
        grpV [ gj ] = 1
    # print "grpV", grpV
    print "Case #" + str(i+1) + ":", len(grpV)


