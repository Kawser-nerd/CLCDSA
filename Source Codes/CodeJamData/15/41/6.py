dd = {
    '^': (-1,0),
    '>': (0,1),
    'v': (1,0),
    '<': (0,-1),
}

for cas in xrange(1,1+input()):
    r, c = map(int, raw_input().strip().split())
    g = [raw_input() for i in xrange(r)]
    sunod = [[None]*c for i in xrange(r)]
    ans = 0
    for i in xrange(r):
        for j in xrange(c):
            if g[i][j] == '.':
                sunod[i][j] = (i,j)
            else:
                di,dj = dd[g[i][j]]
                ni = i + di
                nj = j + dj
                while 0 <= ni < r and 0 <= nj < c:
                    if g[ni][nj] != '.':
                        sunod[i][j] = (ni,nj)
                        break
                    ni += di
                    nj += dj

            if not sunod[i][j]:
                ans += 1

    good = True
    for i in xrange(r):
        for j in xrange(c):
            if not sunod[i][j]:
                okay = False
                for symb, (di, dj) in dd.items():
                    ni = i + di
                    nj = j + dj
                    while 0 <= ni < r and 0 <= nj < c:
                        if g[ni][nj] != '.':
                            okay = True
                            break
                        ni += di
                        nj += dj

                    if okay:
                        break

                if not okay:
                    good = False
                    break

        if not good:
            break

    print "Case #%s:" % cas,
    if good:
        print ans
    else:
        print 'IMPOSSIBLE'
