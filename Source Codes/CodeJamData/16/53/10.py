"""
asteroid escape plan that minimizes the max jump distance

may jump at any instant but must jump at least every S seconds

V = 0 for all asteroids in small data set but not large... so for small case
you can just do all jumps right away. then solution is smallest jump size such that graph of asteroids is connected; can solve by dividing
"""

import math

def solve(s, p, v):
    n = len(p)
    def dist(i, j):
        return math.sqrt((p[i][0] - p[j][0])**2 +
                         (p[i][1] - p[j][1])**2 +
                         (p[i][2] - p[j][2])**2)
    edges = []
    for i in xrange(n):
        for j in xrange(i + 1, n):
            edges.append((dist(i, j), i, j))
    edges.sort()
    rep = [None] * n
    def find(i):
        while rep[i] is not None:
            i = rep[i]
        return i
    comp_count = len(p)
    for (d, i, j) in edges:
        i = find(i)
        j = find(j)
        if i != j:
            comp_count -= 1
            rep[j] = i
        if find(0) == find(1):
            return d

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        n, s = [int(x) for x in readline().split()]
        p = []
        v = []
        for j in xrange(n):
            tokens = [int(x) for x in readline().split()]
            p.append(tokens[:3])
            v.append(tokens[3:])
        print "Case #%d: %g" % (i + 1, solve(s, p, v))
