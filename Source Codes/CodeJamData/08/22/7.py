#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Google CodeJam - Round 1
Task B -

Solution by Joao Moreno <alph.pt@gmail.com> 2008

Usage: python [source_file] < [input_file] > [output_file]
"""

class Partition(object):
    def __init__(self, n):
        self.n = n
        self.l = [-1] * n
    
    def rep(self, i):
        if self.l[i] < 0:
            return i
        else:
            r = self.rep(self.l[i])
        self.l[i] = r
        return r
    
    def union(self, i, j):
        ir = self.rep(i)
        jr = self.rep(j)
        
        if ir == jr:
            return
        
        if self.l[ir] < self.l[jr]:
            self.l[jr] = ir
        elif self.l[ir] > self.l[jr]:
            self.l[ir] = jr
        else:
            self.l[ir] += self.l[jr]
            self.l[jr] = ir
        
        self.n -= 1
    
    def size(self):
        return self.n

def primes(n): 
	if n==2: return [2]
	elif n<2: return []
	s=range(3,n+1,2)
	mroot = n ** 0.5
	half=(n+1)/2-1
	i=0
	m=3
	while m <= mroot:
		if s[i]:
			j=(m*m-3)/2
			s[j]=0
			while j<half:
				s[j]=0
				j+=m
		i=i+1
		m=2*i+3
	return [2]+[x for x in s if x]


if __name__ == '__main__':
    from codejam.io import Scanner
    s = Scanner()
    N = s.readInt()
    l = primes(1000)
    for i in range(1,N+1):
        [A,B,P] = [s.readInt() for k in range(3)]
        p = Partition(B-A+1)
        for a in range(A,B+1):
            for b in range(a+1,B+1):
                for n in l:
                    if n >= P and a % n == 0 and b % n == 0:
                        p.union(a-A,b-A)
        print "Case #%i: %i" % (i,p.size())
