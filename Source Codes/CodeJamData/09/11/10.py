#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from __future__ import division
from StringIO import StringIO
import sys
from pdb import set_trace as debugger
import pprint

def happy(cachebase,base,n):
	assert n>=1
	
	foo = []
	while True:
		if len(cachebase) < n:
			cachebase += [None]*(n-len(cachebase))
		foo.append(n)

		if cachebase[n-1] is not None:
			for i in foo:
				cachebase[i-1] = cachebase[n-1]
			return cachebase[n-1]
		sum = 0
		while n:
			n,d = divmod(n,base)
			sum += d*d
		n = sum
		if n in foo:
			for i in foo:
				cachebase[i-1] = False
			return False
	

def process3(cache,base,min):
	cachebase = cache.get(base,[True])
	if not cachebase:
		cache[base] = cachebase
	while not happy(cachebase,base,min):
			min += 1
	return min
	

def process2(cache,bases):
	oldmin = None
	min = 2
	while True:
		for base in bases:
			min = process3(cache,base,min)
		if min == oldmin:
			return min
		oldmin = min
		

def process(f, out = None):
	if isinstance(f,str):
		if not out:
			out = open(f+'.out.txt','wb')
		f = open(f,'rb')
	else:
		if not out:
			out = StringIO()
	t = int(f.readline().strip())
	cache = {}
	for xm1 in range(t):
		bases = map(int,f.readline().strip().split())
		min_ = process2(cache,bases)
		out.write('Case #%d: %d\n' % (xm1+1,min_))

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		print out.getvalue()
		return out.getvalue()

TEST_DATA=(
"""3
2 3
2 3 7
9 10""",
"""Case #1: 3
Case #2: 143
Case #3: 91
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