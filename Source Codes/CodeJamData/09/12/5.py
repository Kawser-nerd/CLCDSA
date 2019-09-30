from sys import stdin
from heapq import *

def main():
    n, m = map(int, stdin.readline().split())
    c = []
    for _ in xrange(n):
        v = map(int, stdin.readline().split())
        c.append([(v[3*i], v[3*i+1], v[3*i+2]) for i in xrange(m)])
    d = [[10**11]*(2*m) for _ in xrange(2*n)]
    def relax(w, z, t):
        if t < d[w][z]:
            d[w][z] = t
            heappush(h, (d[w][z], (w,z)))
    def ctime(x, s, w, t):
        a = s + w
        y = (x-t)%a
        if y < s:
            return x
        else:
            return x + a - y
    def proc(x, y):
        cnx, cny = x//2, y//2
        dx = 1 - 2*(x%2)
        dy = 1 - 2*(y%2)
        t = d[x][y]
        if 0 <= x+dx < 2*n:
            cs, cw, ct = c[cnx][cny]
            relax(x+dx, y, ctime(t, cs, cw, ct)+1)
        if 0 <= x-dx < 2*n:
            relax(x-dx, y, t+2)
        if 0 <= y+dy < 2*m:
            cs, cw, ct = c[cnx][cny]
            cs, cw, ct = cw, cs, ct+cs
            relax(x, y+dy, ctime(t, cs, cw, ct)+1)
        if 0 <= y-dy < 2*m:
            relax(x, y-dy, t+2)
    d[2*n-1][0] = 0
    h = [(0, (2*n-1,0))]
    while True:
        try:
            tt, p = heappop(h)
        except IndexError:
            break
        if d[p[0]][p[1]] == tt:
            #print tt, p
            proc(p[0], p[1])

    return str(d[0][2*m-1])

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())
