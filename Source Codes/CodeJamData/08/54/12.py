import sys

def getints(ifile):
    return tuple([int(x) for x in ifile.readline().split()])




def foo2(ifile):
    h, w, r = getints(ifile)
    a = [[0] * (w+2) for i in range(h+2)]
    
    for i in range(r):
        x, y = getints(ifile)
        a[x-1][y-1] = -1

    a[0][0] = 1

    for i in range(h):
        for j in range(w):
            
            if a[i][j] <= 0:
                continue
            a[i][j] %= 10007
            if a[i+2][j+1] != -1:
                a[i+2][j+1] += a[i][j]
            if a[i+1][j+2] != -1:
                a[i+1][j+2] += a[i][j]

    return a[h-1][w-1]
                

        
    

def foo(idx, ifile):
    res = foo2(ifile)

    print 'Case #%s: %s' % (idx, res)

def main():
    ifile = file(sys.argv[1])
    n = int(ifile.readline().strip())
    for i in range(n):
        foo(i+1, ifile)

if __name__ == '__main__':
    main()
