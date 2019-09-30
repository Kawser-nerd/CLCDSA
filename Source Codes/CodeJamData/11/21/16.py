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

def average(l):
	return sum(l)/len(l)

def process2(scoreboard):
	N = len(scoreboard)
	l = []
	for i in xrange(N):
		played,won = 0,0
		for p,w in scoreboard[i]:
			played += p
			won += w
		assert played >= 2
		l.append((played,won))
	totals = tuple(l)
	l = []
	for i in xrange(N):
		ll = []
		for j in xrange(N):
			p,w = scoreboard[j][i]
			if not p:
				continue
			op,ow = totals[j]
			assert op-p >= 1
			ll.append((ow-w)/(op-p))
		l.append(average(ll))
		ll = None
	OWPs = tuple(l)
	l = []
	for i in xrange(N):
		ll = []
		for j in xrange(N):
			p,w = scoreboard[i][j]
			if not p:
				continue
			ll.append(OWPs[j])
		l.append(average(ll))
	OOWPs = tuple(l)
	l = None
	ret = []
	for i in xrange(N):
		tp,tw = totals[i]
		RPI = 0.25 * (tw/tp) + 0.50 * OWPs[i] + 0.25 * OOWPs[i]
		ret.append(str(RPI))
	return ret

MAP = {'1':(1,1),'0':(1,0),'.':(0,0)}.__getitem__

def process(f_, out = None):
	T_, = map(int,f_.readline().strip().split())
	for X_ in range(1,T_+1):
		N, = map(int,f_.readline().strip().split())
		scoreboard = []		
		for i_ in xrange(N):
			input = f_.readline().strip()
			assert len(input) == N
			scoreboard.append(map(MAP,input))
		output = process2(scoreboard)
		out.write('Case #%d:\n%s\n' % (X_,'\n'.join(output)))
		out.flush()

TEST_DATA=('''
2
3
.10
0.1
10.
4
.11.
0.00
01.1
.10.
	Case #1:
0.5
0.5
0.5
Case #2:
0.645833333333
0.368055555556
0.604166666667
0.395833333333

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
			d=d.split('Case #1:',1)
			return d[0].strip(), 'Case #1:' + d[1].rstrip() + '\n'
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