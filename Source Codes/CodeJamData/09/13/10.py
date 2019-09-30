#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from __future__ import division
from StringIO import StringIO
import sys
from pdb import set_trace as debugger
import pprint

def process2(c,n):
	p = [1.0] + [0.0]*c
	p3_ = [None]*(c+1)
	nn = 0
	cumul = 0
	remaining = 1.0
	oldremaining = None
	for i in range(c):
		p3 = [1.0] + [0.0]*(n)
		for j in range(n):
			p4 = [0.0]*(n+1)
			for k in range(n):
				p3k = p3[k]
				if not p3k:
					continue
				ppp = (i+k-j)/(c-j)
				p4[k] += p3k * ppp
				p4[k+1] += p3k * (1-ppp)
			p3=p4
		p3_[i] = p3
	while remaining > 1e-10 or oldremaining == remaining:
		oldremaining = remaining
		p2 = [0.0]*(c+1)
		for i in range(c):
			pi,p3 = p[i],p3_[i]
			for j in range(n+1):
				if i+j > c:
					if p3[j]:
						debugger()
					assert p3[j] == 0
					continue
				p2[i+j] += pi*p3[j]
		p=p2
		nn+=1
		cumul += nn*p[c]
		remaining -= p[c]
		p[c] = 0
	return cumul

def process(f, out = None):
	if isinstance(f,str):
		if not out:
			out = open(f+'.out.txt','wb')
		f = open(f,'rb')
	else:
		if not out:
			out = StringIO()
	t = int(f.readline().strip())
	base = 'welcome to code jam'
	for xm1 in range(t):
		c,n = map(int,f.readline().strip().split())
		guess = process2(c,n)
		out.write('Case #%d: %.7f\n' % (xm1+1,guess))

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		print out.getvalue()
		return out.getvalue()

TEST_DATA=(
"""2
2 1
3 2""",
"""Case #1: 3.0000000
Case #2: 2.5000000
""")

def go():
	assert process(StringIO(TEST_DATA[0])) == TEST_DATA[1]
	l = sys.argv[1:]
	if not l:
		l = ['C-small-attempt0.txt', 'C-large.in.txt']
	for x in l:
		process(x)

if __name__ == '__main__':
	go()