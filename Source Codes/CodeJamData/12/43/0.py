import sys
import random
sys.setrecursionlimit(3000)

def bar(a, nx, x):
    return [y-nx for y in a[nx:x]]

def foo2(a, level, height):
    #print a, level, height
    picks = [0]
    i = 0
    n = len(a)
    while True:
        if a[i] == n:
            break
        if a[i] > n:
            return None
        picks.append(a[i])
        i = a[i]
    picks.append(n)

    res = []
    nx = 0
    for x in picks:
        if x == nx:
            res.append(height - level*(n-x))
        else:
            t = foo2(bar(a, nx, x), level+1, height-level*(n-x))
            if t is None:
                return None
            res += t
            #res.append(height - level*(n-x))
        nx = x+1
    return res




def foo(ifile):
    n = int(ifile.readline())
    a = [int(x)-1 for x in ifile.readline().split()]

    level = 0
    height = 1000000
    res = foo2(a, level, height)
    if res is None:
        return "Impossible"
    else:
        return " ".join([str(x) for x in res])


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))
        sys.stdout.flush()


main()

