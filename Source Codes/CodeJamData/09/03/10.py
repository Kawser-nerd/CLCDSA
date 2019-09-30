#!/usr/bin/python
#
# Copyright (c) 2009 by T. Chan.

from StringIO import StringIO
import re		
import sys
from pdb import set_trace as debugger
import pprint

def process(f, out = None):
	if isinstance(f,str):
		if not out:
			out = open(f+'.out.txt','wb')
		f = open(f,'rb')
	else:
		if not out:
			out = StringIO()
	n = int(f.readline().strip())
	base = 'welcome to code jam'
	for xm1 in range(n):
		search = f.readline().strip()
		counts = map(lambda x:(x == base[0] and 1 or 0), search)
		rangelensearch = range(len(search))
		for char in base[1:]:
			counts = map(lambda j:(search[j] == char and sum(counts[:j])%10000 or 0),rangelensearch)
		out.write('Case #%d: %04d\n' % (xm1+1,sum(counts)%10000))

	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		print out.getvalue()
		return out.getvalue()

TEST_DATA=(
"""3
elcomew elcome to code jam
wweellccoommee to code qps jam
welcome to codejam""",
"""Case #1: 0001
Case #2: 0256
Case #3: 0000
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