# coding: utf-8

import heapq


def coord_on_edge(x, y, R, C):
    if y == 0:
        return x
    if x == R:
        return R + y
    if y == C:
        return R + C + R - x
    if x == 0:
        return 2 * (R + C) - y
    return None


def on_edge(x1, y1, x2, y2, R, C, i, edge_points):
    c1 = coord_on_edge(x1, y1, R, C)
    c2 = coord_on_edge(x2, y2, R, C)
    if c1 is not None and c2 is not None:
        heapq.heappush(edge_points, (c1, i))
        heapq.heappush(edge_points, (c2, i))


def solve():
    R, C, N = map(int, input().split())
    edge_points = []            # (coord, point#)
    for i in range(N):
        x1, y1, x2, y2 = map(int, input().split())
        on_edge(x1, y1, x2, y2, R, C, i, edge_points)
    q = []
    while edge_points:
        c, i = heapq.heappop(edge_points)
        # print((c, i))           # dbg
        if len(q) and q[-1] == i:
            q.pop()
        else:
            q.append(i)
    if len(q):
        return "NO"
    return "YES"


print(solve())