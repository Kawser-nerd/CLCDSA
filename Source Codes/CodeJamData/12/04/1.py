#!/usr/bin/env python2.7
#coding=UTF-8

# Copyright © 2009-2012 by T. Chan.

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
from fractions import Fraction as Rat

def process4(room,(x,y),(tX,tY)):
	d = max(abs(x-tX),abs(y-tY))
	dX = cmp(tX,x)
	dY = cmp(tY,y)
	assert {dX,dY} <= {-1,0,1}
	assert bool(dX) ^ bool(dY)
	while d:
		next = room[y+dY][x+dX]
		if next:
			if room[y][x] == '':
				return d == 1
			dX = -dX
			dY = -dY
		elif next == '':
				return d == 1
		else:
			x += dX
			y += dY
		d -= 1
	return False

def process3(room,(x,y),(tX,tY)):
	if x == tX or y == tY:
		return process4(room,(x,y),(tX,tY))
	sX = sY = Rat(0.5)
	tX,tY = map(Rat,(tX-x,tY-y))
	tYtX = Rat(tY,tX)
	tXtY = Rat(tX,tY)
	sgnX = cmp(tX,0)
	sgnY = cmp(tY,0)
	assert {sgnX,sgnY} <= {-1,1}
	maxx = 200
	while 1:
		maxx -= 1
		if not maxx:
			debug()
		if tX > 0:
			dX = 1-sX
		else:
			dX = -sX
		dY = dX*tYtX # dX/tX*tY
		if tY > 0:
			dY2 = 1-sY
		else:
			dY2 = -sY
		if abs(dY2) < abs(dY):
			assert abs(dY2*tXtY) < abs(dX)
			dY,dY2 = dY2,dY
			dX = dY*tXtY
		if abs(tX) < abs(dX) or abs(tY) < abs(dY):
			return sX+tX == 0.5 and sY + tY == 0.5 and room[y][x] == ''
		if dY2 == dY:
			nextX = max(0,sgnX)
			nextY = max(0,sgnY)
			assert nextX == sX+dX
			assert nextY == sY+dY
			assert 0 <= nextX <= 1 and 0 <= nextY <= 1
			if sX+nextX == 1 and sY + nextY == 1 and room[y][x] == '':
				return False
			if room[y+sgnY][x+sgnX]:
				hm = room[y][x+sgnX]
				vm = room[y+sgnY][x]
				if hm and vm:
					tX = dX-tX
					sgnX = -sgnX
					tY = dY-tY
					sgnY = -sgnY
				elif hm:
					tX = dX-tX
					sgnX = -sgnX
					tY -= dY
					tYtX,tXtY = -tYtX,-tXtY
					y += sgnY
					nextY -= sgnY
				elif vm:
					tX -= dX
					tY = dY-tY
					sgnY = -sgnY
					tYtX,tXtY = -tYtX,-tXtY
					x += sgnX
					nextX -= sgnX
				else:
					return False
			else:
				tX -= dX
				x += sgnX
				nextX -= sgnX
				tY -= dY
				y += sgnY
				nextY -= sgnY
		else:
			nextX = sX+dX
			nextY = sY+dY
			assert 0 <= nextX <= 1 and 0 <= nextY <= 1
			if sX+nextX == 1 and sY + nextY == 1 and room[y][x] == '':
				return False
			if nextX == 0 or nextX == 1:
				assert not (nextY == 0 or nextY == 1)
				if room[y][x+sgnX]:
					tX = dX-tX
					sgnX = -sgnX
					tYtX,tXtY = -tYtX,-tXtY
				else:
					tX -= dX
					x += sgnX
					nextX -= sgnX
				tY -= dY
			else:
				assert nextY == 0 or nextY == 1
				if room[y+sgnY][x]:
					tY = dY-tY
					sgnY = -sgnY
					tYtX,tXtY = -tYtX,-tXtY
				else:
					tY -= dY
					y += sgnY
					nextY -= sgnY
				tX -= dX
		assert 0 <= nextX <= 1 and 0 <= nextY <= 1
		sX = nextX
		sY = nextY

def approxeq(a,b):
	return abs(a-b) < 1e-6

def process3float(room,(x,y),(tX,tY)):
	if x == tX or y == tY:
		return process4(room,(x,y),(tX,tY))
	sX = sY = 0.5
	tX,tY = tX-x,tY-y
	tYtX = tY/tX
	tXtY = tX/tY
	sgnX = cmp(tX,0)
	sgnY = cmp(tY,0)
	assert {sgnX,sgnY} <= {-1,1}
	maxx = 200
	while 1:
		maxx -= 1
		if not maxx:
			debug()
		if tX > 0:
			dX = 1-sX
		else:
			dX = -sX
		dY = dX*tYtX # dX/tX*tY
		if tY > 0:
			dY2 = 1-sY
		else:
			dY2 = -sY
		if abs(dY2) < abs(dY):
			assert abs(dY2*tXtY) < abs(dX)+0.000001
			dY,dY2 = dY2,dY
			dX = dY*tXtY
		if abs(tX) < abs(dX) or abs(tY) < abs(dY):
			return approxeq(sX+tX,0.5) and approxeq(sY + tY, 0.5) and room[y][x] == ''
		nextX = sX+dX
		nextY = sY+dY
		assert -0.000001 <= nextX <= 1.000001 and -0.000001 <= nextY <= 1.000001
		if approxeq(sX+nextX,1) and approxeq(sY+nextY,1) and room[y][x] == '':
			return False
		if approxeq(dY2, dY):
			assert approxeq(nextX,max(0,sgnX))
			assert approxeq(nextY,max(0,sgnY))
			if room[y+sgnY][x+sgnX]:
				hm = room[y][x+sgnX]
				vm = room[y+sgnY][x]
				if hm and vm:
					tX = dX-tX
					sgnX = -sgnX
					tY = dY-tY
					sgnY = -sgnY
				elif hm:
					tX = dX-tX
					sgnX = -sgnX
					tY -= dY
					tYtX,tXtY = -tYtX,-tXtY
					y += sgnY
					nextY -= sgnY
				elif vm:
					tX -= dX
					tY = dY-tY
					sgnY = -sgnY
					tYtX,tXtY = -tYtX,-tXtY
					x += sgnX
					nextX -= sgnX
				else:
					return False
			else:
				tX -= dX
				x += sgnX
				nextX -= sgnX
				tY -= dY
				y += sgnY
				nextY -= sgnY
		else:
			if approxeq(nextX,0) or approxeq(nextX,1):
				assert not (approxeq(nextY,0) or approxeq(nextY,1))
				if room[y][x+sgnX]:
					tX = dX-tX
					sgnX = -sgnX
					tYtX,tXtY = -tYtX,-tXtY
				else:
					tX -= dX
					x += sgnX
					nextX -= sgnX
				tY -= dY
			else:
				assert (approxeq(nextY,0) or approxeq(nextY,1))
				if room[y+sgnY][x]:
					tY = dY-tY
					sgnY = -sgnY
					tYtX,tXtY = -tYtX,-tXtY
				else:
					tY -= dY
					y += sgnY
					nextY -= sgnY
				tX -= dX
		assert -0.000001 <= nextX <= 1.000001 and -0.000001 <= nextY <= 1.000001
		sX = nextX
		sY = nextY

def process2(room,(x,y),D):
	ret = 0
	for dX in xrange(-D,D+1):
		for dY in xrange(-D,D+1):
			if not (0 < dX*dX+dY*dY <= D*D):
				continue
			if process3float(room,(x,y),(x + dX,y + dY)):
				ret += 1
	return ret

def process(f_, out = None):
	T_, = map(int,f_.readline().strip().split())
	for X_ in range(1,T_+1):
		H,W,D = map(int,f_.readline().strip().split())
		room = []
		pos = None
		for i_ in xrange(H):
			input = f_.readline().strip()
			if 'X' in input:
				pos=(input.find('X'),i_)
			input = tuple({'#':True,'.':False,'X':''}[c] for c in input)
			room.append(input)
		output = process2(room,pos,D)
		out.write('Case #%d: %s\n' % (X_,output))
		out.flush()

TEST_DATA=(r'''
6
3 3 1
###
#X#
###
3 3 2
###
#X#
###
4 3 8
###
#X#
#.#
###
7 7 4
#######
#.....#
#.....#
#..X..#
#....##
#.....#
#######
5 6 3
######
#..X.#
#.#..#
#...##
######
5 6 10
######
#..X.#
#.#..#
#...##
######
Case #1: 4
Case #2: 8
Case #3: 68
Case #4: 0
Case #5: 2
Case #6: 28
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
