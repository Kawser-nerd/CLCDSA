#!/usr/bin/python
#
# Copyright (c) 2009 by Teanlorg Chan.

from StringIO import StringIO
import re		

def process(f, out = None):
	if isinstance(f,str):
		if not out:
			out = open(f+'.out.txt','wb')
		f = open(f,'rb')
	else:
		if not out:
			out = StringIO()
	l,d,n = map(int,f.readline().strip().split())
	words = []
	for i in range(d):
		words.append(f.readline().strip())
	for i in range(n):
		pattern = f.readline().strip()
		pattern = pattern.replace('(','[').replace(')',']')
		expr = re.compile('^' + pattern + '$')
		count = len(filter(lambda x:expr.match(x), words))
		out.write('Case #%d: %s\n' % (i+1, count))
	#f.close()
	#out.close()
	if isinstance(out,StringIO):
		return out.getvalue()

TEST_DATA=(
"""3 5 4
abc
bca
dac
dbc
cba
(ab)(bc)(ca)
abc
(abc)(abc)(abc)
(zyx)bc""",
"""Case #1: 2
Case #2: 1
Case #3: 3
Case #4: 0
""")

def go():
	assert process(StringIO(TEST_DATA[0])) == TEST_DATA[1]
	for x in ['A-large.in.txt']:
		process(x)

if __name__ == '__main__':
	go()