for case in xrange(1,1+int(raw_input())):
    r = int(raw_input())
    a = [[0 for i in range(101)] for j in range(101)]
    numcells = 0
    for rect_index in xrange(r):
        [x1,y1,x2,y2] = [int(z) for z in raw_input().split()]
        for x in xrange(x1,x2+1):
            for y in xrange(y1,y2+1):
                if a[x][y] == 0:
                    numcells += 1
                    a[x][y] = 1
    generations = 0
    while (numcells > 0):
        generations += 1
        for i in range(100,0,-1):
            for j in range(100,0,-1):
                if (a[i][j] != a[i-1][j]) and (a[i][j] != a[i][j-1]):
                    numcells += (a[i-1][j] - a[i][j])
                    a[i][j] = a[i-1][j]
    print "Case #%d: %d" %(case, generations)
