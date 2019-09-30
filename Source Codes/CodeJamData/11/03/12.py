#!/usr/bin/python
#coding=UTF-8

# Copyright © 2009-2011 by T. Chan.

# date -u '+%F %T %z %s'
# Reading start: 2011-05-07 00:43:02 +0000 1304728982 to 2011-05-07 00:48:35 +0000 1304729315
#                2011-05-07 00:51:45 +0000 1304729505
# Code start:    2011-05-07 00:53:09 +0000 1304729589
# Test pass:     
# Small dl:      
# Small fail:    
# Small accept:  
# Large dl:      
# Large submit:  
# Complete:      

from __future__ import division
from StringIO import StringIO
import sys, os, re, os.path, pprint, time, operator
from pdb import set_trace as debug
from math import hypot,pi,sin,cos,tan,sqrt,floor,ceil,asin

if not 'set' in globals():
	from sets import Set as set
	from sets import ImmutableSet as frozenset

def process2(Cs):
	if reduce(operator.xor, Cs):
		return 'NO'
	return sum(Cs)-min(Cs)

def process(f_, out = None):
	T_, = map(int,f_.readline().strip().split())
	for X_ in range(1,T_+1):
		input = f_.readline().strip()

		N = int(input)
		input = f_.readline().strip()
		input = map(int,input.split())
		Cs = input
		assert len(Cs) == N

		output = process2(Cs)
		
		out.write('Case #%d: %s\n' % (X_,output))
		out.flush()

TEST_DATA=('''
2
5
1 2 3 4 5
3
3 5 6
	Case #1: NO
Case #2: 11

''')

def process_test(d):
	f_ = StringIO(d)
	out = StringIO()

	process(f_,out)

	ret = out.getvalue()
	return ret

def process_file(fn,auto=False):
	f_ = open(fn,'rb')

	if fn.endswith('.in'):
		fn = fn[:-3]
	elif fn.endswith('.in.txt'):
		fn = fn[:-7]

	while True:
		i = 0
		path = '%s.out%d.txt'%(fn,i)
		if os.path.exists(path):
			if auto:
				f_.close()
				return
			continue
		out = open(path,'wb')
		break
	del i

	process(f_,out)

	f_.close()
	out.close()


def main():
	def td(d):
		if isinstance(d,str):
			d=d.split('Case #1: ',1)
			return d[0].strip(), 'Case #1: ' + d[1].rstrip() + '\n'
		return d
	
	def ts(prefix='>'):
		print prefix+time.strftime(' %F %T %z %s',time.gmtime())

	l = sys.argv[1:]
	ts('+')
	if not l:
		if not TEST_DATA.strip():
			return
		test_input,expected_output=td(TEST_DATA)
		my_output = process_test(test_input)
		if my_output != expected_output:
			print >>sys.stderr, "!!! Wrong output."
			print >>sys.stderr, my_output
			return
		mydir,myfile = os.path.split(__file__)
		assert os.path.abspath(mydir) == os.path.abspath(os.path.curdir)
		if myfile.endswith('.py') and len(myfile) == 3:
			expr = re.compile(r'\A%s\-(?:small|large)\-.*\.in(?:\.txt)\Z'%myfile.upper())
			for f in os.listdir(mydir):
				if expr.match(f):
					ts('@')
					print '>> %s'%f
					process_file(f,auto=True)
	for x in l:
		ts('@')
		print '>> %s'%x
		process_file(x)
	ts('=')

if __name__ == '__main__':
	main()