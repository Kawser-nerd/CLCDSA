#!/usr/bin/env python2.7
#coding=UTF-8

# Copyright © 2009-2012 by T. Chan.

# Reading start: A end
# Code start:    
# Test pass:     
# Small dl:      
# Small run:     
# Small accept:  
# Large dl:      
# Large run:     
# Large submit:  
# Complete:      


from __future__ import division,with_statement
#from __future__ import absolute_import,
#from __future__ import print_function
import __builtin__,sys,os,os.path,re,time,StringIO as io
import operator,array,itertools,bisect
import pprint,pdb,traceback,warnings
from pdb import set_trace as debug
from math import hypot,pi,sin,cos,tan,sqrt,floor,ceil,asin
from itertools import islice,izip,imap
try:
	import collections
	from collections import namedtuple,deque
except: pass
try: from math import fsum
except: warnings.warn("math.fsum() not supported; aliasing it to sum"); fsum = sum
if not 'set' in __builtin__.__dict__: from sets import Set as set,ImmutableSet as frozenset

def process2(S,p,scores):
	ret = 0
	for tsc in scores:
		sc,extra = tsc//3,tsc%3
		if sc + (1 if extra else 0) >= p:
			ret += 1
		elif S and ((extra == 2 and sc+2 >= p) or (extra == 0 and sc > 0 and sc+1 >= p)):
			ret += 1
			S -= 1
	return ret

def process(f_, out = None):
	T_, = map(int,f_.readline().strip().split())
	for X_ in range(1,T_+1):
		input = map(int,f_.readline().strip().split())
		N,S,p = input[:3]
		scores = input[3:]
		assert len(scores) == N
		output = process2(S,p,scores)
		out.write('Case #%d: %s\n' % (X_,output))
		out.flush()

TEST_DATA=(r'''
4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21

Case #1: 3
Case #2: 2
Case #3: 1
Case #4: 3
''',
#r'''  '''
)

# Running
def assertdebug(func):
	try:
		assert False
		return func
	except AssertionError:
		pass
	def pmfunc(*args,**kwargs):
		try:
			return func(*args,**kwargs)
		except:
			traceback.print_exc()
			pdb.post_mortem()
			raise
	return pmfunc
process=assertdebug(process)

def process_test(d):
	f_ = io.StringIO(d)
	out = io.StringIO()

	process(f_,out)

	ret = out.getvalue()
	return ret

def process_file(fn,auto=False):
	for ext in ('.in', '.in.txt', ''):
		if fn.endswith(ext):
			base = fn[:-len(ext)] if ext else fn
			break
	i = 0
	while True:
		path = '%s.out%d.txt'%(base,i)
		path2 = 'broken-'+path
		if not (os.path.exists(path) or os.path.exists(path2)):
			break
		if auto:
			print "! %s exists"%path
			return
		i += 1
	print ">> %s"%path

	success = None
	try:
		with open(fn,'rb') as f_:
			with open(path,'wb') as out:
				process(f_,out)
		success = True
	finally:
		if not success:
			os.rename(path,path2)
	return success

def main():
	def ts(prefix='>',old=[None]):
		t = time.time()
		diff = (old[0] is not None) and ' d%.6f'%(t - old[0]) or ''
		old[0] = t
		print '%s %s %.6f%s'%(prefix,time.strftime('%F %T %z',time.gmtime(t)),t,diff)

	ts(' ')

	mydir,myfile = os.path.split(os.path.join(os.path.curdir,__file__))

	if 'gen' in globals():
		import cPickle as pickle
		cachefile = os.path.join(mydir,myfile+'.pickle')
		if os.path.exists(cachefile):
			with open(cachefile,'rb') as f:
				gen(pickle.load(f))
			ts('g')
		else:
			with open(cachefile,'wb') as f:
				pickle.dump(gen(),f,-1)
			ts('c')
	l = sys.argv[1:]
	auto=False
	if not l:
		def td(d):
			if isinstance(d,str):
				d=d.split('Case #1:',1)
				return d[0].strip(), 'Case #1:' + d[1].rstrip() + '\n'
			return d
		for test_data in TEST_DATA:
			if not test_data.strip():
				return
			test_input,expected_output=td(test_data)
			my_output = process_test(test_input)
			if my_output != expected_output:
				print >>sys.stderr, "!!! Wrong output."
				print >>sys.stderr, my_output
				return
			ts('v')
		assert os.path.abspath(mydir) == os.path.abspath(os.path.curdir)
		if myfile.endswith('.py') and len(myfile) == 4:
			expr = re.compile(r'\A%s\-(?:large|small-attempt[0-9]|(?:large|small)\-practice)\.in(?:\.txt)?\Z'%myfile[0].upper())
			auto=True
			for f in os.listdir(mydir):
				if expr.match(f):
					l.append(f)
	for x in l:
		ts('.')
		print '<< %s'%x
		if x == '-':
			process(sys.stdin,sys.stdout)
		else:
			process_file(x,auto=auto)
		ts('>')

if __name__ == '__main__':
	main()
