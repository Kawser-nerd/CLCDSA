#!/usr/bin/python

# google code jam - c.durr - 2010
# Making Chess Boards

from heapq import *


T = int(raw_input())
for t in range(T):
    M,N = map(int, raw_input().split())
    #                                         -- read and decode board
    b = [] 
    for _ in range(M):
        l = raw_input()
        s = []
        for c in l:
           s += ("0000"+(bin(int(c, 16))[2:]))[-4:]
        b.append(map(int, s))

    # R[ij] largest checkerboard with top left cell i,j
    R = [[int(i==M-1 or j==N-1) for j in range(N)] for i in range(M)]
    for i in range(M-2,-1,-1):
        for j in range(N-2,-1,-1):
            c = b[i][j]
            if (c!=b[i+1][j] and c!=b[i][j+1] and c==b[i+1][j+1]):
                R[i][j] = 1+min([R[i][j+1],R[i+1][j],R[i+1][j+1]])
            else:
                R[i][j] = 1;

    # sort in decreasing order
    Q = [(-R[i][j],i,j) for i in range(M) for j in range(N)]
    heapify(Q)

    cut = {}
    while (Q):
        mk,i,j = heappop(Q)
        k = -mk
        if (R[i][j]==k):  # can cut
            if k in cut:
                cut[k] += 1
            else:
                cut[k] = 1
            # cut out and update R
            for i1 in range(max(0, i-k+1), min(M,i+k)):
                for j1 in range(max(0, j-k+1), min(N, j+k)):
                    k1 = max(0, i-i1, j-j1)
                    if (R[i1][j1] > k1):
                        R[i1][j1] = k1
                        if (k1>0):
                            heappush(Q, (-k1,i1,j1))

    res = [(k,cut[k]) for k in cut]
    res.sort()
    res.reverse()

    print 'Case #%d:' % (t+1), len(res)
    for (k,nk) in res:
        print k, nk

