import sys
import psyco
from heapq import heappush, heappop
psyco.full()

def calct(t, x1, y1, x2, y2, a):
    if not (x1 // 2 == x2 // 2
            and y1 // 2 == y2 // 2):
        return t + 2
    
    cx = x1 // 2
    cy = y1 // 2
    aa = a[cx][cy]

    if x1 != x2:
        crossX = 0
    else:
        crossX = 1

    mod, t3 = aa
    tm = t % mod 
    last = tm
    for i, j in t3:
        if tm < i and j == crossX:
            return t // mod * mod + last + 1
        last = max(tm, i)

def foo(idx, ifile):
    n,m = [int(x) for x in ifile.readline().split()]
    a = []
    for i in range(n):
        t = [int(x) for x in ifile.readline().split()]
        a.append([])
        for j in range(m):
            t2 = t[3*j:3*j+3]
            t2[2] %= (t2[0] + t2[1])
            mod = t2[0] + t2[1]
            r = t2[2]
            t3 = []
            t3.append((r, 1))
            r += t2[0]
            if r >= mod:
                t3.append((mod, 0))
                t3.append((r%mod, 0))
            else:
                t3.append((r, 0))
                t3.append((mod, 1))
            t3.sort()
            for x, y in t3[:]:
                t3.append((x+mod, y))
            a[-1].append((mod, t3))
    #print a


    n2 = n*2
    m2 = m*2

    b = [[None] * m2 for i in range(n2)]
    end = (0, m2-1)

    q = []
    heappush(q, (0, (n2-1,0)))

    while q:
        res, t = heappop(q)
        x, y = t
        if b[x][y] is not None:
            continue
        b[x][y] = res
        #print x,y,res
        if t == end:
            print 'Case #%d: %d' % (idx, res)
            return

        for dir in ((-1, 0), (1, 0), (0, -1), (0,1)):
            x2 = x + dir[0]
            y2 = y + dir[1]
            if x2 < 0 or x2 >= n2:
                continue
            if y2 < 0 or y2 >= m2:
                continue
            if b[x2][y2] is not None:
                continue
            t2 = calct(res, x, y, x2, y2, a)
            heappush(q, (t2, (x2,y2)))

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        foo(i+1, ifile)

main(sys.stdin)
