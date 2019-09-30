#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from __future__ import division
from StringIO import StringIO
import sys
from pdb import set_trace as debugger
import pprint

def process2(n,l):
	swaps = 0
	length = len(l)
	for i in range(length):
		for j in range(i,length):
			if l[j] <= i:
				swaps += j-i
				temp = l[j:j+1]
				l[j:j+1] = []
				l[i:i] = temp
				break
		else:
			assert False
	return swaps

def processline(s):
	return max(s.rfind('1'),0)

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
		l = []
		for i in range(n):
			l.append(processline(f.readline().strip()))
		guess = process2(n,l)
		out.write('Case #%d: %d\n' % (xm1+1,guess))

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		print out.getvalue()
		return out.getvalue()

TEST_DATA=(
"""3
2
10
11
3
001
100
010
4
1110
1100
1100
1000""",
"""Case #1: 0
Case #2: 2
Case #3: 4
""")

def go():
	assert process(StringIO(TEST_DATA[0])) == TEST_DATA[1]
	l = sys.argv[1:]
	if not l:
		l = ['A-small-attempt0.in.txt', 'A-large.in.txt']
	for x in l:
		process(x)

if __name__ == '__main__':
	go()