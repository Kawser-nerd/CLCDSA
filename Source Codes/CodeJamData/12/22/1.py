# -*- coding: utf-8 -*-
import heapq
import sys


C = []
F = []
H = 0
INF = float('inf')

def time_taken(water_level, floor_level, t):
    if t == 0:
        return 0
    if water_level - floor_level >= 20:
        return 1
    else:
        return 10

def length(a, b, t):
    """
    Time required to move from a to b, starting at time t.
    """
    ca = C[a[0]][a[1]]
    cb = C[b[0]][b[1]]
    fa = F[a[0]][a[1]]
    fb = F[b[0]][b[1]]

    water_level = H - t*10
    # We assume we are on a valid block already

    if fb + 50 > ca:
        # We cannot move there, ever
        return INF

    if max(fa, fb, water_level) + 50 <= cb:
        # We can move immediately
        return time_taken(water_level, fa, t)

    if max(fa, fb) + 50 <= cb:
        # We have to wait for the water level to drop
        drop = water_level - (cb - 50)
        drop_time = drop / 10.0
        return drop_time + time_taken((cb-50), fa, t+drop_time)

    # We cannot move there, ever
    return INF






def Dijkstra(G,start,end=None):
    """
    Find shortest paths from the start vertex to all
    vertices nearer than or equal to the end.

    The input graph G is assumed to have the following
    representation: A vertex can be any object that can
    be used as an index into a dictionary.  G is a
    dictionary, indexed by vertices.  For any vertex v,
    G[v] is itself a dictionary, indexed by the neighbors
    of v.  For any edge v->w, G[v][w] is the length of
    the edge.

    The output is a pair (D,P) where D[v] is the distance
    from start to v and P[v] is the predecessor of v along
    the shortest path from s to v.
    """

    D = {}  # dictionary of final distances
    P = {}  # dictionary of predecessors (previous node)
    Q = []  # queue
    heapq.heappush(Q, (0, start))

    while len(Q) > 0:
        d, v = heapq.heappop(Q)
        if v in D and d > D[v]:
            continue
        if v == end: break

        # Loop through neighbours
        for w in G[v]:
            vwLength = d + length(v, w, d)
            if w in D:
                if vwLength >= D[w]:
                    continue
            D[w] = vwLength
            P[w] = v
            heapq.heappush(Q, (vwLength, w))

    return (D,P)


fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    H, N, M = map(int, fin.readline().split())
    C = []
    F = []
    for i in range(N):
        C.append(map(int, fin.readline().split()))
    for i in range(N):
        F.append(map(int, fin.readline().split()))

    G = {}
    for r in range(N):
        for c in range(M):
            neighbours = []
            a = (r, c)
            if r+1 < N:
                neighbours.append((r+1, c))
            if r-1 >= 0:
                neighbours.append((r-1, c))
            if c+1 < M:
                neighbours.append((r, c+1))
            if c-1 >= 0:
                neighbours.append((r, c-1))
            G[a] = neighbours

    end = (N-1, M-1)
    D, P = Dijkstra(G, (0,0), end)
    print "Case #%d: %s" % (case, D[end])

