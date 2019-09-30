#!/usr/bin/env python2.7

mult = [
    [0,0,0,0,0,0,0,0,0],
    [0,1,2,3,4,5,6,7,8],
    [0,2,5,4,7,6,1,8,3],
    [0,3,8,5,2,7,4,1,6],
    [0,4,3,6,5,8,7,2,1],
    [0,5,6,7,8,1,2,3,4],
    [0,6,1,8,3,2,5,4,7],
    [0,7,4,1,6,3,8,5,2],
    [0,8,7,2,1,4,3,6,5],
]
elements = '01ijk'

T = int(raw_input())
for x in xrange(1, T + 1):
    L, X = map(int, raw_input().split())
    string = raw_input()
    reduced = [0] * (L + 1)
    reduced[0] = 1
    for i, c in enumerate(string):
        reduced[i + 1] = mult[reduced[i]][elements.index(c)]
    p = reduced[-1]
    y = 'NO'
    c = 1
    for i in xrange(X % 8):
        c = mult[c][p]
    if c == 5:
        r = 0
        c = 1
        for i in xrange(min(8, X)):
            for j in xrange(L):
                if mult[c][reduced[j + 1]] == 2:
                    break
            else:
                c = mult[c][p]
                continue
            for j1 in xrange(j + 1, L):
                if mult[c][reduced[j1 + 1]] == 4:
                    y = 'YES'
                    break
            else:
                for i1 in xrange(i + 1, min(i + 9, X)):
                    c = mult[c][p]
                    for j in xrange(L):
                        if mult[c][reduced[j + 1]] == 4:
                            y = 'YES'
                            break
            break
    print 'Case #{}: {}'.format(x, y)
