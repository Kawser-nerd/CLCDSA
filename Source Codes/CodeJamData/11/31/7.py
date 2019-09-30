#!/usr/bin/python

def solve(R, C, p):
    for i in xrange(1, R):
        for j in xrange(1, C):
            if p[i][j] == p[i][j - 1] == p[i - 1][j] == p[i - 1][j - 1] == '#':
                p[i - 1][j - 1] = '/'
                p[i - 1][j] = '\\'
                p[i][j - 1] = '\\'
                p[i][j] = '/'

T = int(raw_input())
for i in range(T):
    R, C = [int(s) for s in raw_input().split()]
    p = []
    for j in xrange(R):
        row = [c for c in raw_input()]
        p.append(row)
    solve(R, C, p)
    print 'Case #%d:' % (i + 1)
    ok = True
    for r in xrange(R):
        for c in xrange(C):
            if p[r][c] == '#':
                ok = False
    if ok:
        for row in p:
            print ''.join(row)
    else:
        print 'Impossible'
