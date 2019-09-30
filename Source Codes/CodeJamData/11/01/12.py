#!/usr/bin/python
#coding=UTF-8

# Copyright © 2009-2011 by T. Chan.

# date -u '+%F %T %z %s'
# Reading start: + 2011-05-06 23:48:12 +0000 1304725692 ish
# Code start:    + 2011-05-06 23:53:02 +0000 1304725982
# Test pass:     2011-05-07 00:14:03 +0000 1304727243
# Small dl:      
# Small fail:    
# Small accept:  
# Large dl:      
# Large submit:  
# Complete:      

from __future__ import division
from StringIO import StringIO
import sys, os, re, os.path, pprint, time
from pdb import set_trace as debug
from math import hypot,pi,sin,cos,tan,sqrt,floor,ceil,asin

if not 'set' in globals():
	from sets import Set as set
	from sets import ImmutableSet as frozenset

def sgn(x):
	if x>0:
		return 1
	if x < 0:
		return -1
	if x == 0:
		return 0
	raise ValueError

def process2(Rs,Pss):
	P = [1,1]
	ret = 0
	for Ri in Rs:
		Pi = Pss[Ri][0]
		del Pss[Ri][0]
		tt = abs(P[Ri]-Pi)+1
		P[Ri] = Pi
		ret += tt
		if Pss[Ri^1]:
			Pj = Pss[Ri^1][0]
			disp2 = Pj-P[Ri^1]
			P[Ri^1] += sgn(disp2)*min(tt,abs(disp2))
	assert Pss == [[],[]]
	return ret

def process(f_, out = None):
	T_, = map(int,f_.readline().strip().split())
	for X_ in range(1,T_+1):
		input = f_.readline().strip()
		input = input.split()
		N,input = int(input[0]),input[1:]
		
		assert len(input) == 2*N

		Rs = []
		Pss = [[],[]]
		for i in range(N):
			Ri = {'O':0,'B':1}[input[2*i]]
			Pi = int(input[2*i+1])
			Rs.append(Ri)
			Pss[Ri].append(Pi)

		output = process2(Rs,Pss)
		#output = '%d'%output
		#output = '%.6f'%output
		
		out.write('Case #%d: %s\n' % (X_,output))
		out.flush()

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

TEST_DATA=('''
3
4 O 2 B 1 B 2 O 4
3 O 5 O 8 B 100
2 B 2 B 1
	Case #1: 6
Case #2: 100
Case #3: 4

''')


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