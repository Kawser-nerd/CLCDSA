#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from __future__ import division
from StringIO import StringIO
import sys
from pdb import set_trace as debugger
import pprint
from math import hypot

def dist(a,b):
	x,y,r = a
	xx,yy,rr = b
	d = hypot(x-xx,y-yy)
	return max(r,rr,(d+r+rr)/2)

def dist2(a,b,other):
	return max(dist(a,b),other[2])

def process2(plants):
	if len(plants) <= 2:
		return max(map(lambda plant:plant[2],plants))
	a,b,c = plants
	return min([
		dist2(a,b,c),
		dist2(b,c,a),
		dist2(c,a,b),
	])
		

def process(f, out = None):
	if isinstance(f,str):
		if not out:
			out = open(f+'.out.txt','wb')
		f = open(f,'rb')
	else:
		if not out:
			out = StringIO()
	t = int(f.readline().strip())
	for xm1 in range(t):
		n = int(f.readline().strip())
		plants = []
		for i in range(n):
			plants.append(tuple(map(int,f.readline().strip().split())))
		guess = process2(plants)
		out.write('Case #%d: %.6f\n' % (xm1+1,guess))
		out.flush()

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		print out.getvalue()
		return out.getvalue()

TEST_DATA=(
"""5
3
20 10 2
20 20 2
40 10 3
3
20 10 3
30 10 3
40 10 3
5
100 100 1
140 100 1
100 130 1
100 500 1
150 500 1
8
100 100 1
110 100 1
100 110 1
110 110 1
200 200 1
210 200 1
200 210 1
210 210 1
4
100 100 1
200 100 1
200 103 1
300 103 1""",
"""Case #1: 7.000000
Case #2: 8.000000
Case #3: 26.000000
Case #4: 8.071067
Case #5: 51
""")

TEST_DATA=(
"""2
3
20 10 2
20 20 2
40 10 3
3
20 10 3
30 10 3
40 10 3
""",
"""Case #1: 7.000000
Case #2: 8.000000
""")

def go():
	assert process(StringIO(TEST_DATA[0])) == TEST_DATA[1]
	l = sys.argv[1:]
	if not l:
		#l = ['A-small-attempt0.in.txt', 'A-large.in.txt']
		pass
	for x in l:
		process(x)

if __name__ == '__main__':
	go()