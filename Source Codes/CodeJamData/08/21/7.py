from sys import stdin

tno = int(stdin.readline())
for i in xrange(tno):
    n, A, B, C, D, X, Y, M = map(int, stdin.readline().strip().split())
    tab = [0]*9
    for _ in xrange(n):
        tab[X%3 + 3*(Y%3)] += 1
        X = (A * X + B) % M
        Y = (C * Y + D) % M
    res = 0
    for x in xrange(3):
        for y in xrange(3):
            z = tab[x + 3*y]
            res += z*(z-1)*(z-2)/6
    for x in xrange(3):
        res += tab[x]*tab[x+3]*tab[x+6]
    for y in xrange(3):
        res += tab[3*y]*tab[3*y+1]*tab[3*y+2]
    perm = [(0,1,2),(0,2,1),(1,0,2),(1,2,0),(2,0,1),(2,1,0)]
    for per in perm:
        res += tab[0 + 3*per[0]]*tab[1 + 3*per[1]]*tab[2 + 3*per[2]]

    print "Case #%d: %d"%(i+1, res)
