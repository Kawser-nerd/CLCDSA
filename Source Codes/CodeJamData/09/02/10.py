#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from StringIO import StringIO
import re		
import sys
from pdb import set_trace as debugger
import pprint

def draincoords(amap,y,x):
	cur = amap[y][x]
	n = s = e = w = cur
	if y-1 >= 0:
		n = amap[y-1][x]
	if y+1 < len(amap):
		s = amap[y+1][x]
	if x+1 < len(amap[y]):
		e = amap[y][x+1]
	if x-1 >= 0:
		w = amap[y][x-1]
	lowest = min(cur,n,s,e,w)
	if lowest == cur:
		return None
	if lowest == n:
		return (y-1,x)
	if lowest == w:
		return (y,x-1)
	if lowest == e:
		return (y,x+1)
	if lowest == s:
		return (y+1,x)
	assert False

def follow(cell):
	next = cell[0]
	while not isinstance(next,str):
		next = next[0]
	return next

def follow2(cell):
	next = cell[0]
	if isinstance(next,str):
		return next
	chain = [cell]
	cell = next
	next = cell[0]
	while not isinstance(next,str):
		if cell in chain:
			print map(lambda x:x[1:],chain)
			debugger()
		assert cell not in chain
		chain.append(cell)
		cell = next
		next = next[0]
	assert isinstance(next,str)
	for cell in chain:
		cell[0] = next
	return next

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
		h,w = map(int,f.readline().strip().split())
		amap = []
		for y in range(h):
			amap.append(map(int,f.readline().strip().split()))
			assert len(amap[-1]) == w
		dmap = map(lambda x:[None]*w,[None]*h)
		for y in range(h):
			for x in range(w):
				dmap[y][x] = [None,y,x]
		#pprint.pprint(amap)
		#pprint.pprint(dmap)
		sink = 0
		for y in range(h):
			for x in range(w):
				coords = draincoords(amap,y,x)
				#print "amap %r %r %r" % (y, x, coords)
				if coords is None:
					dmap[y][x][0] = chr(ord('A')+sink)
					sink += 1
				else:
					yy,xx = coords
					dmap[y][x][0] = dmap[yy][xx]
		#print "foo"
		#print dmap
		out.write('Case #%d:\n' % (xm1+1,))
		bmap = {}
		bnum = 0
		for y in range(h):
			for x in range(w):
				sink = follow2(dmap[y][x])
				basin = bmap.get(sink,None)
				if not basin:
					basin = chr(ord('a')+bnum)
					bnum += 1
					bmap[sink]=basin
				out.write('%s%s' % (basin, (x+1 == w and '\n' or ' ')))

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		return out.getvalue()

TEST_DATA=(
"""5
3 3
9 6 3
5 9 6
3 5 9
1 10
0 1 2 3 4 5 6 7 8 7
2 3
7 6 7
7 6 7
5 5
1 2 3 4 5
2 9 3 9 6
3 3 0 8 7
4 9 8 9 8
5 6 7 8 9
2 13
8 8 8 8 8 8 8 8 8 8 8 8 8
8 8 8 8 8 8 8 8 8 8 8 8 8""",
"""Case #1:
a b b
a a b
a a a
Case #2:
a a a a a a a a a b
Case #3:
a a a
b b b
Case #4:
a a a a a
a a b b a
a b b b a
a b b b a
a a a a a
Case #5:
a b c d e f g h i j k l m
n o p q r s t u v w x y z
""")

def go():
	assert process(StringIO(TEST_DATA[0])) == TEST_DATA[1]
	l = sys.argv[1:]
	if not l:
		l = ['B-small-attempt0.txt', 'B-large.in.txt']
	for x in l:
		process(x)

if __name__ == '__main__':
	go()