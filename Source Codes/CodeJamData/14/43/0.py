#! /usr/bin/env python

import sys
import heapq
fin = open(sys.argv[1], "r")
fout = open("p3.out", "w")

def blockdist(b1, b2):
    yd = max(b1[1] - b2[3], b2[1] - b1[3])
    xd = max(b1[0] - b2[2], b2[0] - b1[2])
    return max(xd, yd) - 1

def mindist(adj, n):
    vis = [False for i in xrange(n)]
    dist = [10000 for i in xrange(n)]
    dist[0] = 0
    Q = zip(dist, range(n))
    heapq.heapify(Q)
    while Q:
        u = heapq.heappop(Q)[1]

        if vis[u]:
            continue
        elif u == n-1:
            break
        else:
            vis[u] = True

        for v in xrange(n):
            if not vis[v] and dist[u] + adj[u][v] < dist[v]:
                dist[v] = dist[u] + adj[u][v]
                heapq.heappush(Q, (dist[v], v))

    return dist[n-1]

T = int(fin.readline())
for i in xrange(T):
    print i
    W, H, B = map(int, fin.readline().split())

    blocks = [[] for j in xrange(B)]
    dists = [[0 for j in xrange(B + 2)] for k in xrange(B + 2)]
    for j in xrange(B):
        blocks[j] = map(int, fin.readline().split())
        for k in xrange(j):
            dists[j+1][k+1] = blockdist(blocks[j], blocks[k])
            dists[k+1][j+1] = dists[j+1][k+1]

    for j in xrange(B):
        dists[0][j+1] = blocks[j][0]
        dists[j+1][0] = blocks[j][0]
        dists[j+1][B+1] = W - blocks[j][2] - 1
        dists[B+1][j+1] = W - blocks[j][2] - 1

    dists[0][B+1] = W

    fout.write("Case #" + str(i+1) + ": " + str(mindist(dists, B+2)) + "\n")
