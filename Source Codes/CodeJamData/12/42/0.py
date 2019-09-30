import sys
import random


def calc(a, w, l, b):
    res = [[None, None] for i in range(len(a))]
    cx = 0.0
    cy = None
    ny = 0.0

    i = b[0]
    res[i] = [0.0, 0.0]
    cx = a[i]
    ny = a[i]

    for i in b[1:]:
        if cx + a[i] <= w:
            ix = cx+a[i]
            if cy is None:
                iy = 0.0
                ny = max(ny, a[i])
            else:
                iy = cy + a[i]
                if iy > l:
                    return None
            res[i] = [ix, iy]
            cx = ix + a[i]
            ny = max(ny, iy+a[i])
        else:
            ix = 0.0
            iy = ny + a[i]
            if iy > l:
                return None
            res[i] = [ix, iy]
            cx = a[i]
            cy = ny
            ny = iy+a[i]
    return ' '.join([' '.join([str(y) for y in x]) for x in res])

def foo(ifile):
    n, w, l = [int(x) for x in ifile.readline().split()]
    a = [float(x) for x in ifile.readline().split()]
    while True:
        b = range(n)
        random.shuffle(b)
        res = calc(a, w, l, b)
        if res is not None:
            return res

def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

