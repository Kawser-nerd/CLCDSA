#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Google CodeJam - Round 1
Task C -

Solution by Joao Moreno <alph.pt@gmail.com> 2008

Usage: python [source_file] < [input_file] > [output_file]
"""

class PerfectDeck(object):
    def __init__(self, K):
        self.l = [0] * K
        pos = range(K)
        n = 1
        old_p = 0
        while n <= K:
            p = (n - 1 + old_p) % len(pos)
            self.l[pos[p]] = n
            del pos[p]
            n += 1
            old_p = p
    
    def at(self,i):
        return self.l[i-1]

if __name__ == '__main__':
    from codejam.io import Scanner
    s = Scanner()
    N = s.readInt()
    for i in range(1,N+1):
        K = s.readInt()
        d = PerfectDeck(K)
        n = s.readInt()
        l = [d.at(s.readInt()) for j in range(n)]
        print "Case #%i:" % (i),
        for a in l:
            print a,
        print ""
