#!/usr/bin/env python
from sys import stdin

tn = int(stdin.readline())
for ti in xrange(tn):
	n, p = map(int, stdin.readline().split())
	g = map(int, stdin.readline().split())
        m = [0]*p
        for gi in g:
            m[gi%p] += 1
        r = m[0]
        if p == 2:
            r += (m[1]+1)//2
        elif p == 3:
            x = min(m[1], m[2])
            r += x
            m[1] -= x
            m[2] -= x
            r += (m[1]+2)//3
            r += (m[2]+2)//3
        else:
            r += m[2]//2
            m[2] = m[2]%2
            x = min(m[1], m[3])
            r += x
            m[1] -= x
            m[3] -= x
            r += (m[1]+3)//4
            r += (m[3]+3)//4
            if m[1]%4 + m[3]%4 == 0:
                r += m[2]
	print 'Case #{0}:'.format(ti+1), r
