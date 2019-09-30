import sys
import psyco
from numpy import linalg
psyco.full()

def p(a, b):
    if b < 0:
        return 0
    if a < b:
        return 0
    if b*2 > a:
        return p (a, a-b)
    res = 1
    for i in range(b):
        res *= a - i
    for i in range(b):
        res //= (i+1)
    return res

def foo(ifile):
    n, c = [int(x) for x in ifile.readline().split()]
    pnc = p(n,c)

    
    res = []
    for i in range(c, n):
        t = [0.0] * (n+1)
        for j in range(i,n+1):
            ii = n - i
            jj = j - i
            t[j] = (p(ii, jj) * p(i, c-jj)+0.0)/pnc
        t[i] -= 1.0
        t = t[c:]
        res.append(t)

    t = [0] * (n+1-c)
    t[0] = 1
    res.append(t)

    t2 = [1.0] * (n+1-c)
    return '%.7f' % linalg.solve(res, t2)[-1]




def main(ifile):
    n = int(ifile.readline())
    for  i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main(sys.stdin)
