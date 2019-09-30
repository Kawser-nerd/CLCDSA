import sys

def foo(ifile):
    n = int(ifile.readline())

    a = {}

    for i in range(n):
        t = [int(x) for x in ifile.readline().split()]
        for i1 in range(t[0], t[2]+1):
            for i2 in range(t[1], t[3]+1):
                a[(i1, i2)] = 1

    res = 0
    while a:
        b = {}
        for x, y in a:
            if (x-1, y+1) in a:
                b[(x, y+1)] = 1
            if (x+1, y-1) in a:
                b[(x+1, y)] = 1
            if (x-1, y) in a or (x, y-1) in a:
                b[(x, y)] = 1
        a = b
        res += 1
    return res

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))
    


if __name__ == '__main__':
    main(sys.stdin)
