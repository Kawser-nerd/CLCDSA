#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from __future__ import division
from StringIO import StringIO
import sys
from pdb import set_trace as debugger
import pprint

def diggable0(r,c,f,a,positions):
	p2 = []
	for (y,x) in positions:
		for o in [1,-1]:
			yy,xx = y,x+o
			if ((yy,xx) in positions or a[yy*(c+2)+(xx)] == 0) and a[(yy+1)*(c+2)+(xx)] == 1:
				yy += 1
				while a[(yy+1)*(c+2)+(xx)] == 0:
					yy += 1
				if (yy,xx) not in p2:
					p2.append((yy,xx))
	return p2

def diggable(r,c,f,a,(y,x), digs):
	p2 = []
	for o in [1,-1]:
		yy,xx = y,x+o
		if (a[yy*(c+2)+(xx)] == 0 or (yy,xx) in digs) and a[(yy+1)*(c+2)+(xx)] == 1 and (yy+1,xx) not in digs:
			p2.append((yy+1,xx))
	return p2

def movable(r,c,f,a,(y,x),digs):
	p2 = []
	for o in [1,-1]:
		yy,xx = y,x+o
		if a[yy*(c+2)+(xx)] == 0 or (yy,xx) in digs:
			while a[(yy+1)*(c+2)+(xx)] == 0 or (yy+1,xx) in digs:
				yy += 1
			if yy-y <= f:
				p2.append((yy,xx))
	return p2

def process2(r,c,f,a):
	pos_dig = [([(1,1)],[])]
	digs = 0
	#print a
	while True:
		pos_dig2 = []
		#print "###"
		for pd in pos_dig:
			#print pd
			pq = pd[0]
			positions = []
			while pq:
				p = pq.pop()
				if p in positions:
					continue
				if p[0] >= r:
					return digs
				positions.append(p)
				pq.extend(movable(r,c,f,a,p,pd[1]))
			#print positions
			for p in positions:
				for d in diggable(r,c,f,a,p,pd[1]):
					#print "Dug %r" % (d,)
					pd2 = ([p],pd[1]+[d])
					#assert pd2[1].sort() is None and pd2 not in pos_dig2
					pd2[1].sort()
					if pd2 in pos_dig2:
						continue
					pos_dig2.append(pd2)
		if not pos_dig2:
			return -1
		pos_dig = pos_dig2
		digs += 1
			
		

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
		r,c,ff = map(int,f.readline().strip().split())
		a = []
		a += [2]*(c+2)
		for i in range(r):
			s = f.readline().strip()
			a += [2] + map(lambda x:{ '.' : 0, '#' : 1 }[x],s) + [2]
		a += [2]*(c+2)
		guess = process2(r,c,ff,a)
		out.write('Case #%d: %s\n' % (xm1+1,(guess>=0 and 'Yes %d' % guess or 'No')))

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		print out.getvalue()
		return out.getvalue()

TEST_DATA=(
"""4
5 8 3
........
########
...#.###
####..##
###.##..
2 2 1
.#
##
3 3 1
...
###
###
3 2 1
..
#.
..""",
"""Case #1: Yes 2
Case #2: No
Case #3: Yes 3
Case #4: No
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