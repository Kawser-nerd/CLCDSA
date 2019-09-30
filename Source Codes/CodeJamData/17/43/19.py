#!/usr/bin/env python
from sys import stdin, stdout
from z3 import *

tn = int(stdin.readline())
for ti in xrange(tn):
    r, c = map(int, stdin.readline().split())
    m = [stdin.readline().strip() for _ in xrange(r)]
    b = [[[] for i in xrange(c)] for j in xrange(r)]
    s = Solver()
    for i in xrange(r):
        for j in xrange(c):
            if m[i][j] == '-' or m[i][j] == '|':
                b[i][j] = Bool('b'+str(i)+','+str(j))
                def check(x, y, val, d):
                    while True:
                        if x < 0 or x >= r or y < 0 or y >= c:
                            return
                        if m[x][y] == '-' or m[x][y] == '|':
                            s.add(b[i][j] != val)
                            return
                        if m[x][y] == '#':
                            return
                        if m[x][y] == '/':
                            if d == 0:
                                d = 1
                            elif d == 1:
                                d = 0
                            elif d == 2:
                                d = 3
                            else:
                                d = 2
                        if m[x][y] == '\\':
                            if d == 0:
                                d = 3
                            elif d == 3:
                                d = 0
                            elif d == 1:
                                d = 2
                            else:
                                d = 1
                        if m[x][y] == '.':
                            b[x][y].append((i, j, val))
                        if d == 0:
                            y += 1
                        elif d == 1:
                            x -= 1
                        elif d == 2:
                            y -= 1
                        elif d == 3:
                            x += 1
                check(i, j+1, True, 0)
                check(i-1, j, False, 1)
                check(i, j-1, True, 2)
                check(i+1, j, False, 3)
    def conv(bijk):
        x, y, val = bijk
        if val:
            return b[x][y]
        return Not(b[x][y])
    try:
        for i in xrange(r):
            for j in xrange(c):
                if m[i][j] == '.':
                    assert len(b[i][j]) > 0
                    s.add(Or(*map(conv, b[i][j])))
        s.check()
        mo = s.model()
        print 'Case #{0}:'.format(ti + 1), 'POSSIBLE'
        for i in xrange(r):
            for j in xrange(c):
                if m[i][j] == '-' or m[i][j] == '|':
                    stdout.write('-' if mo[b[i][j]] else '|')
                else:
                    stdout.write(m[i][j])
            stdout.write('\n')
    except:
        print 'Case #{0}:'.format(ti + 1), 'IMPOSSIBLE'

