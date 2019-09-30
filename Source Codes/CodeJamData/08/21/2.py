import sys


def foo(idx, ifile):
    n, A, B, C, D, x0, y0, M = tuple([int(x) for x in ifile.readline().split()])

    a = []
    a.append((x0, y0))

    for i in range(n-1):
        x0 = x0 * A + B
        x0 %= M
        y0 = y0 * C + D
        y0 %= M
        a.append((x0, y0))

    b = [[0]*3 for i in range(3)]

    for x in a:
        t1 = x[0] % 3
        t2 = x[1] % 3
        b[t1][t2] += 1

    res = 0
    for i in range(9):
        x1 = i // 3
        y1 = i % 3
        for j in range(i,9):
            x2 = j // 3
            y2 = j % 3
            x3 = (9 - x1 - x2) % 3
            y3 = (9 - y1 - y2) % 3
            k = x3 * 3 + y3
            if k < j:
                continue
            if i == j and j == k:
                t = b[x1][y1]
                res += t * (t-1) * (t-2) / 6
            elif i == j:
                t1 = b[x1][y1]
                t2 = b[x3][y3]
                res += t1 * t2 * (t1-1)/2
            elif j == k:
                t1 = b[x1][y1]
                t2 = b[x3][y3]
                res += t1 * t2 * (t2-1)/2
            else:
                t1 = b[x1][y1]
                t2 = b[x2][y2]
                t3 = b[x3][y3]
                res += t1 * t2 * t3
    print 'Case #%i: %s' % (idx, res)
             
                
            
            
            
        

def main():
    ifile = file(sys.argv[1])
    n = int(ifile.readline().strip())
    for i in range(n):
        foo(i+1, ifile)

if __name__ == '__main__':
    main()
