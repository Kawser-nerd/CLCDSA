import sys

def split(a):
    if len(a) == 1:
        yield a, []
        return

    for x in split(a[1:]):
        yield a[:1]+x[0], x[1]
        yield x[0], a[:1]+x[1]

def calc(a):
    if len(a) == 0:
        return 0.0
    if len(a) == 1:
        return a[0][2]

    res = None
    for i in range(len(a)):
        for j in range(i):
            dx = a[i][0] - a[j][0]
            dy = a[i][1] - a[j][1]
            d = (dx*dx+dy*dy)**0.5
            d += a[i][2] + a[j][2]
            if res is None:
                res = d / 2.0
            if d/2.0 > res:
                res = d / 2.0
    return res
    

def foo(ifile):
    n = int(ifile.readline())
    a = [[float(y) for y in ifile.readline().split()] for i in range(n)]

    res = None
    for x, y in split(a):
        if res is None:
            res = max(calc(x), calc(y))
        else:
            res = min(res, max(calc(x), calc(y)))
    return '%.6f' % res

def main(ifile):
    n = int(ifile.readline())
    for  i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main(sys.stdin)
