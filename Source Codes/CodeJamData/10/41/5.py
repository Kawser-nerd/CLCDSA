# -*- coding: utf-8 -*-
import sys
fin = open(sys.argv[1], 'r')

def best(k, rows):
    m = []
    for p in range(len(rows)):
        working = True
        #print p
        for r in rows:
            #print r
            for i, a in enumerate(r):
                q = i*2 + k - len(r)
                o = p*2 - q
                j = (o + len(r) - k)/2

                if j < 0 or j >= len(r):
                    continue
                #print i, j
                if a != r[j]:
                    working = False
                    break
        if working:
            shift = abs((k-1)-p)
            #print p, shift, k
            m.append(shift)
    # print "."
    return min(m)

def size(k):
    t = 0
    for i in range(2*k-1):
        t += k-abs(k-i-1)
    return t

N = int(fin.readline())
for case in range(1,N+1):
    k = int(fin.readline())
    rows = []
    S = 2*k-1
    for i in range(S):
        rows.append(map(int, fin.readline().split()))
    cols = [[] for i in range(S)]
    for i, row in enumerate(rows):
        for p, a in enumerate(row):
            c = 2*p + k - len(row)
            cols[c].append(a)
    #print rows
    #print cols
    a = best(k, rows)
    b = best(k, cols)
    #print a, b
    shift = a + b
    result = size(k+shift) - size(k)

    print "Case #%d: %s" % (case, result)

fin.close()