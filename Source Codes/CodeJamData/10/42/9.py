# -*- coding: utf-8 -*-
#INF = 10000000000000
INF = float("infinity")
import sys
fin = open(sys.argv[1], 'r')
N = int(fin.readline())
for case in range(1,N+1):
    P = int(fin.readline())
    M = map(int, fin.readline().split())
    prices = []
    for i in range(P):
        prices.append(map(int, fin.readline().split()))

    last = []
    for i in range(2**P):
        m = M[i]
        s = []
        for j in range(P+2):
            if j <= m:
                s.append(0)
            else:
                s.append(INF)
        last.append(s)

        #for j in range(P-M[i]):
        #    playing[P-j-1][i/(2**(P-j))] = True
    n = len(last)
    #print last
    for k in range(P):
        n /= 2
        next = []
        for i in range(n):
            s = []
            cost = prices[k][i]
            for j in range(P+1):
                p = min(last[2*i][j] + last[2*i+1][j] + cost, last[2*i][j+1] + last[2*i+1][j+1])
                s.append(p)
            s.append(INF)
            next.append(s)
        last = next
        #print last

    #print last
    print "Case #%d: %s" % (case, last[0][0])
fin.close()