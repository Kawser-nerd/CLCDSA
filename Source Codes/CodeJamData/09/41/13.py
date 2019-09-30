import sys
#import psyco
#psyco.full()


def enum(a):
    if len(a) == 1:
        yield a
        return
    for i in range(len(a)):
        for x in enum(a[:i] + a[i+1:]):
            yield [a[i]] + x

def calc(a):
    a = a[:]
    res = 0
    for i in range(len(a)):
        while a[i] != i:
            res += 1
            j = a[i]
            a[i] = a[j]
            a[j] = j
    return res

def check(a, x, y):
    n = len(a)
    for i in range(n):
        for j in range(i+1, n):
            if(a[x[i]][y[j]]):
                return False
#    print x, y
    return 1
        

def foo(ifile):
    n = int(ifile.readline())

    a = [[0]*n for i in range(n)]
    for i in range(n):
        a[i] = [x=='1' for x in ifile.readline().strip()]


    b = [0] * n
    for i in range(n):
        t = 0
        for j in range(n):
            if a[i][j]:
                t = j
        b[i] = t+1

    res = 0
    for i in range(n):
        if b[i] <= i+1:
            continue
        for j in range(i+1,n):
            if b[j] <= i+1:
                b[i:j+1] = b[j:j+1]+b[i:j]
                res += j - i
                break
    return res

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main(sys.stdin)
