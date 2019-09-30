import sys

def run2(a, i, X, Y):
    n = len(a)
    for x in range(n):
        for y in range(n):
            t = a[x][y]
            x2 = x+X
            y2 = y+Y

            coords = [(i-x2-1, i-y2-1),
                      (y2, x2),
                      (i-y2-1, i-x2-1)]

            for x2, y2 in coords:
                x3 = x2 - X
                y3 = y2 - Y
                if 0 <= x3 < n and 0 <= y3 < n and a[x3][y3] != t:
                    return 0
    return 1
    

def run(a, i):
    n = len(a)
    for X in range(i-n+1):
        for Y in range(i-n+1):
            if(run2(a, i, X, Y)):
                return (X, Y)
            
    return 0
    

def foo(ifile):
    n = int(ifile.readline())

    a = [[None]* n for i in range(n)]

    for i in range(n):
        t = [int(x) for x in ifile.readline().split()]
        for j in range(len(t)):
            a[j][i-j] = t[j]
    for i in range(1, n):
        t = [int(x) for x in ifile.readline().split()]
        for j in range(len(t)):
            a[j+i][n-j-1] = t[j]
    #for x in a:
    #    print x

    i = n
    while 1:
        res = run(a, i)
        if res:
            #print res, 'wow'
            return i*i -n*n
        i += 1
        

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))
    


if __name__ == '__main__':
    main(sys.stdin)
