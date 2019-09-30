import sys

def calc(a, i, j, n):
    dx = a[j][0] - a[i][0]
    return a[j][0] + min(dx, a[j][1])

def foo(ifile):
    n = int(ifile.readline())
    a = [[int(x) for x in ifile.readline().split()] for i in range(n)]
    d = int(ifile.readline())

    b = [None] * n
    b[0] = a[0][0]*2
    for i in range(n):
        if b[i] is None:
            continue
        if b[i] >= d:
            return 'YES'
        for j in range(i+1, n):
            if a[j][0] > b[i]:
                continue
            b[j] = max(b[j], calc(a, i, j, b[i]))
            if b[j] >= d:
                return 'YES'
    return 'NO'



def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

