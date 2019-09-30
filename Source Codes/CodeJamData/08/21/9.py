#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Google CodeJam - Round 1
Task A - 

Solution by Joao Moreno <alph.pt@gmail.com> 2008

Usage: python [source_file] < [input_file] > [output_file]
"""

class Triangle(object):
    def __init__(self, x1,y1,x2,y2,x3,y3):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.x3 = x3
        self.y3 = y3
    
    def isCenterInt(self):
        x = self.x1 + self.x2 + self.x3
        y = self.y1 + self.y2 + self.y3
        if float(x)/3 == x/3 and float(y)/3 == y/3:
            return True
        else:
            return False

if __name__ == '__main__':
    from codejam.io import Scanner
    s = Scanner()
    N = s.readInt()
    for i in range(1,N+1):
        [n,A,B,C,D,x,y,M] = [s.readInt() for k in range(8)]
        l = [(x,y)]
        for j in range(1,n):
            x = (A * x + B) % M
            y = (C * y + D) % M
            l.append((x,y))
        r = 0
        while len(l) > 2:
            p = l[0]
            l = l[1:]
            for a in range(len(l)):
                for b in range(a,len(l)):
                    if l[a] is not l[b] and Triangle(p[0],p[1],l[a][0],l[a][1],l[b][0],l[b][1]).isCenterInt():
                        r += 1
        print "Case #%i: %i" % (i,r)
