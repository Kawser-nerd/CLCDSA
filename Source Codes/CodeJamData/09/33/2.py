#!/usr/bin/python

# google code jam - c.durr - 2009

# bribe the prisoners
# dyn progr
# r[i] = i-th prisoners cell number, r[0], r[Q+1] added as borders
# A[i][j] = min cost of releasing prisoners between door i and j+1
#           cells i and j+1 are already empty


T = int(raw_input())
for t in range(T):
    P,Q =  map(int, raw_input().split())
    p = map(int, raw_input().split())
    r = [0] + p + [P+1]

    A = [[0 for j in range(Q+1)] for i in range(Q+1)]

    for d in range(1,Q+1):
        for i in range(Q+1-d):
            j = i+d        # j in range(i+1,Q+1)
            for k in range(i+1, j+1):
                alt = r[j+1]-r[i]-2 + A[i][k-1]+A[k][j]
                if k==i+1 or alt<A[i][j]:
                    A[i][j] = alt

    print "Case #%i:"% (t+1), A[0][Q]
    
