#!/usr/local/bin/python2.7
#coding=UTF-8

# Copyright © 2009-2011 by T. Chan.

# Reading start: 
# Code start:    
# Test pass:     
# Small dl:      
# Small run:     
# Small accept:  
# Large dl:      
# Large run:     
# Large submit:  
# Complete:      

from __future__ import division
from StringIO import StringIO
import sys, os, re, os.path, time, operator,__builtin__,array
import pprint,pdb,traceback
from pdb import set_trace as debug
from math import hypot,pi,sin,cos,tan,sqrt,floor,ceil,asin

if not 'set' in __builtin__.__dict__:
	from sets import Set as set
	from sets import ImmutableSet as frozenset

def process4(D,tup1,tup2):
	w1,e1,dw1,de1 = tup1
	w2,e2,dw2,de2 = tup2
	assert e1 + D - w2 >= 0
	overlap = e1+D-w2
	assert overlap >= 0
	d1,d2 = 0,0
	if dw1 < de2:
		d1 = min(overlap,de2-dw1)
		overlap -= d1
	elif dw1 > de2:
		d2 = min(overlap,dw1-de2)
		overlap -= d2
	assert d1 >= 0 and d2 >= 0
	d1 += overlap/2
	d2 += overlap/2
	ret = w1-d1,e2+d2,max(dw1+d1,dw2-d2),max(de1-d1,de2+d2)
	return ret

def process3(D,PVi):
	P,V = PVi
	assert V
	d = D*(V-1)/2.0
	w = P-d
	e = P+d
	return (w,e,d,d)

def process2(D,PV):
	ret = 0
	l = []
	for tup in PV:
		tup = process3(D,tup)
		while True:
			if not l or l[-1][1] + D < tup[0]:
				ret = max(ret,tup[2],tup[3])
				l.append(tup)
			else:
				tup=process4(D,l.pop(),tup)
				continue
			break
	return ret

def process(f_, out = None):
	T_, = map(int,f_.readline().strip().split())
	for X_ in range(1,T_+1):
		C, D = map(int,f_.readline().strip().split())
		PV = []
		for i_ in xrange(C):
			P,V = map(int,f_.readline().strip().split())
			PV.append((P,V))
		PV.sort()
		output = process2(D,PV)
		output = '%.6f'%output
		out.write('Case #%d: %s\n' % (X_,output))
		out.flush()

TEST_DATA=('''
2
3 2
0 1
3 2
6 1
2 2
0 3
1 1
	Case #1: 1.0
Case #2: 2.5

''')

def assertdebug(func):
	try:
		assert False
		return func
	except AssertionError:
		pass
	def pmfunc(*args,**kwargs):
		try:
			func(*args,**kwargs)
		except:
			traceback.print_exc()
			pdb.post_mortem()
	return pmfunc
process=assertdebug(process)

def process_test(d):
	f_ = StringIO(d)
	out = StringIO()

	process(f_,out)

	ret = out.getvalue()
	return ret

def process_file(fn,auto=False):
	if fn.endswith('.in'):
		base = fn[:-3]
	elif fn.endswith('.in.txt'):
		base = fn[:-7]
	else:
		base = fn

	i = 0
	while True:
		path = '%s.out%d.txt'%(base,i)
		if not os.path.exists(path):
			break
		if auto:
			print "! %s exists"%path
			return
		i += 1
	print ">> %s"%path
	f_ = open(fn,'rb')
	out = open(path,'wb')

	process(f_,out)

	f_.close()
	out.close()

def main():
	def td(d):
		if isinstance(d,str):
			d=d.split('Case #1: ',1)
			return d[0].strip(), 'Case #1: ' + d[1].rstrip() + '\n'
		return d
	
	def ts(prefix='>',old=[None]):
		t = time.time()
		diff=''
		if old[0] is not None:
			diff = ' d%.6f'%(t - old[0])
		old[0] = t
		print '%s %s %.6f%s'%(prefix,time.strftime('%F %T %z',time.gmtime(t)),t,diff)

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
		if myfile.endswith('.py') and len(myfile) == 4:
			expr = re.compile(r'\A%s\-(?:large|small-attempt[0-9]|(?:large|small)\-practice)\.in(?:\.txt)?\Z'%myfile[0].upper())
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