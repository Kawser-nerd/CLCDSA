import sys

sys.setrecursionlimit(100000)

inp = sys.stdin
outp = sys.stdout

def minv(x):
    return int(''.join(['0']+x).replace('?', '0'))

def maxv(x):
    return int(''.join(['0']+x).replace('?', '9'))

def best(A, B):
    d1 = abs(A[0]-A[1])
    d2 = abs(B[0]-B[1])
    if d1 != d2:
        return A if d1 < d2 else B
    if A[0] != B[0]:
        return A if A[0] < B[0] else B
    return A if A[1] < B[1] else B


def doit(x, y):
    L = len(x)
    if L == 0:
        return (0, 0)

    X = 0
    Y = 0
    if x[0] != '?':
        X = int(x[0]) * (10**(L-1))
    if y[0] != '?':
        Y = int(y[0]) * (10**(L-1))
        
    if x[0] != '?' and y[0] != '?':
        if x[0] < y[0]:
            return (maxv(x), minv(y))
        elif x[0] > y[0]:
            return (minv(x), maxv(y))
        R = doit(x[1:], y[1:])
        return (X+R[0], Y+R[1])
    
    C = (0, 10**L)

#    print 'doit %s %s -> %s %d %d' % (x, y, C, X, Y)

    if x[0] == '?' and y[0] == '?':
        x[0] = y[0] = '0'
        C = best(C, doit(x, y))
        x[0] = y[0] = '?'
    elif x[0] == '?':
        x[0] = y[0]
        C = best(C, doit(x, y))
        x[0] = '?'
    elif y[0] == '?':
        y[0] = x[0]
        C = best(C, doit(x, y))
        y[0] = '?'

    if x[0] == '?':
        if Y < 9*10**(L-1):
            C = best(C, (Y+10**(L-1)+minv(x[1:]),
                         Y+maxv(y[1:])))
        if Y > 0:
            C = best(C, (Y-10**(L-1)+maxv(x[1:]),
                         Y+minv(y[1:])))

    if y[0] == '?':
        if X < 9*10**(L-1):
            C = best(C, (X+maxv(x[1:]),
                         X+10**(L-1)+minv(y[1:])))
        if X > 0:
            C = best(C, (X+minv(x[1:]),
                         X-10**(L-1)+maxv(y[1:])))
    return C
            
def solve():
    (x,y) = map(list, sys.stdin.readline().split())
    L = len(x)
    (c,j) = doit(x,y)
    
    print '%0*d %0*d' % (L, c, L, j)










T = int(inp.readline())
for i in range(T):
    outp.write('Case #%d: ' % (i+1))
    solve()
