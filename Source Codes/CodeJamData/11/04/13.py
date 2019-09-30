#!/usr/bin/python
#coding=UTF-8

# Copyright © 2009-2011 by T. Chan.

# date -u '+%F %T %z %s'
# Reading start: 2011-05-07 00:48:35 +0000 1304729315 to 2011-05-07 00:51:45 +0000 1304729505
#                2011-05-07 00:57:09 +0000 1304729829
# Code start:    
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

def cycles(p):
	p = list(p)
	ret = [0]*(len(p))
	for i in range(len(p)):
		if p[i] is None:
			continue
		c = -1
		while True:
			next = p[i]
			p[i] = None
			i = next
			if i is None:
				break
			c += 1
		ret[c] += 1
	return ret

E = [None,0]

def e(n):
	if not (n < len(E)):
		ret = 1
		for i in range(1,n):
			ret += 1/i * e(i)
		ret *= n/(n-1)
		assert len(E) == n
		E[n:] = [ret]
	return E[n]

def process2(perm):
	return ret

def sorted(l):
	l = list(l)
	l.sort()
	return l

def process(f_, out = None):
	T_, = map(int,f_.readline().strip().split())
	for X_ in range(1,T_+1):
		N = int(f_.readline().strip())
		input = f_.readline().strip().split()
		perm = map(lambda x:int(x)-1,input)
		assert sorted(perm) == range(N)

		output = 0
		for i in range(N):
			if perm[i] != i:
				output += 1
		#output = '%d'%output
		output = '%.6f'%output
		
		out.write('Case #%d: %s\n' % (X_,output))
		out.flush()

TEST_DATA=('''
3
2
2 1
3
1 3 2
4
2 1 4 3
	Case #1: 2.000000
Case #2: 2.000000
Case #3: 4.000000

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

def main2():
	def perms(l):
		if not l:
			yield []
			return
		for i in range(len(l)):
			l2 = list(l)
			x = l2.pop(i)
			for p in perms(l2):
				p.append(x)
				yield p
	def calcf(n):
		ret = [0]*n
		for p in perms(range(n)):
			l = cycles(p)
			ret = map(operator.add,ret,l)
		return tuple(ret)
	def fact(n):
		ret = 1
		while n:
			ret *= n
			n -= 1
		return ret
	f = []
	for i in range(1,7):
		f.append(calcf(i))
	pprint.pprint(f)
	for i in range(len(f)):
		fi = fact(i+1)
		print map(lambda x:fi/x,f[i])
	for i in range(10):
		print e(i)

if __name__ == '__main__':
	main()