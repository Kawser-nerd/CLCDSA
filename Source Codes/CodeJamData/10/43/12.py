
filename = 'C-small'

N = 110

fin = open(filename + '.in')
fout = open(filename + '.out', 'w')
cases = int(fin.readline().strip())
for case in xrange(1, cases + 1):
    map1 = []
    map2 = []
    for p in xrange(N):
        map1.append([False] * N)
        map2.append([False] * N)
    r = int(fin.readline().strip())
    for p in xrange(r):
        x1, y1, x2, y2 = [int(x) for x in fin.readline().strip().split()]
        for i in xrange(x1, x2 + 1):
            for j in xrange(y1, y2 + 1):
                map1[i][j] = True
                map2[i][j] = True
    r = 0
    while True:
        s = 0
        r += 1
        for i in xrange(1, N):
            for j in xrange(1, N):
                if map1[i][j]:
                    if not map1[i - 1][j] and not map1[i][j - 1]:
                        map2[i][j] = False
                    else:
                        map2[i][j] = True
                        s += 1
                else:
                    if map1[i - 1][j] and map1[i][j - 1]:
                        map2[i][j] = True
                        s += 1
                    else:
                        map2[i][j] = False
        map1, map2 = map2, map1
        if s == 0:
            break
    print r
    fout.write('Case #%d: %d\n' % (case, r))
fin.close()
fout.close()
