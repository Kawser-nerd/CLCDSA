import sys

def calc(a, b):
    if a[0] > b[0]:
        return calc(b, a)

    for i in range(len(a)):
        if(a[i] >= b[i]):
            return False
    return True
        

def foo(ifile):
    n, k = [int(x) for x in ifile.readline().split()]
    a = [[int(x) for x in ifile.readline().split()] for i in range(n)]
    a.sort()

    b = [[None] * n for i in range(n)]
    for i in range(n):
        for j in range(i):
            b[i][j] = calc(a[i], a[j])
            b[j][i] = b[i][j]

    c = [0]
    for i in range(n):
        d = []
        for x in c:
            ok = 0
            for j in range(i):
                if not (x & (1 << j)):
                    continue
                if b[i][j]:
                    d.append(x - (1<<j) + (1<<i))
                    ok = 1
            if not ok:
                d.append(x + (1<<i))
        c = d

    res = n
    for x in c:
        t = 0
        while x:
            if x % 2 == 1:
                t += 1
            x //= 2
        res = min(t, res)
    return res


def main(ifile):
    n = int(ifile.readline())
    for  i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main(sys.stdin)
