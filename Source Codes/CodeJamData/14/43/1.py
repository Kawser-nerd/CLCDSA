__author__ = 'tian'

from itertools import product
from collections import deque


def rl(T):
    return list(map(T, raw_input().split()))


class Block:
    def __init__(self, x0, y0, x1, y1):
        self.x0 = x0
        self.y0 = y0
        self.x1 = x1
        self.y1 = y1


class Graph:
    def __init__(self, n):
        self.n = n
        self.e = [[] for _ in range(n)]

    def add_edge(self, a, b, v):
        self.e[a].append((b, v))

        #print('addedge', a, b, v)

    def min_dist(self, s, t):
        n = self.n
        e = self.e

        d = [10 ** 40 for i in range(n)]
        q = deque()
        inq = [False for i in range(n)]

        d[s] = 0
        q.append(s)
        inq[s] = True
        #print('mindist,begin',s,t)
        while len(q) > 0:
            i = q.popleft()
            inq[i] = False

            #print(i)
            #print(d)

            for j, v in e[i]:
                if d[j] > d[i] + v:
                    d[j] = d[i] + v
                    if not inq[j]:
                        inq[j] = True
                        q.append(j)
            #print(d)

        #print('mindist', s, t, d)
        return d[t]


def d(xa1, xa2, xb1, xb2, ya1, ya2, yb1, yb2):
    dx = 0
    dy = 0
    if xa2 < xb1:
        dx = xb1 - xa2
    if xb2 < xa1:
        dx = xa1 - xb2
    if ya2 < yb1:
        dy = yb1 - ya2
    if yb2 < ya1:
        dy = ya1 - yb2

    return max(dx,dy)


    min_v = 10 ** 40

    for xa, xb, ya, yb in product([xa1, xa2], [xb1, xb2], [ya1, ya2], [yb1, yb2]):
        print(xa,xb,ya,yb)
        v = max(abs(xa - xb), abs(ya - yb))
        min_v = min(min_v, v)
    #print('')
    #print(xa1, xa2, xb1, xb2, ya1, ya2, yb1, yb2,' ',min_v)
    return min_v


def solve(W, H, B):
    #print(W,H,B)
    m = len(B)
    n = m + 2
    s = m
    t = m + 1

    g = Graph(n)

    g.add_edge(s, t, W)
    for i in range(m):
        g.add_edge(s, i, min(B[i].x0, B[i].x1))
        g.add_edge(i, t, W - max(B[i].x0, B[i].x1))

        for j in range(m):
            if i != j:
                v = d(B[i].x0, B[i].x1, B[j].x0, B[j].x1, B[i].y0, B[i].y1, B[j].y0, B[j].y1)

                g.add_edge(i, j, v)

    ans = g.min_dist(s, t)
    return ans


def main():
    T, = rl(int)

    for C in range(1, T + 1):
        W, H, N = rl(int)
        B = []
        for i in range(N):
            x0, y0, x1, y1 = rl(int)
            b = Block(x0, y0, x1 + 1, y1 + 1)
            B.append(b)
        ans = solve(W, H, B)
        print('Case #%d: %d' % ( C, ans ) )


main()