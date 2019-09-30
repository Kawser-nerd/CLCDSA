# -*- coding: utf-8 -*-

from __future__ import division
import math
from collections import defaultdict as dd, namedtuple

class Point(list):
	def __init__(s,x,y):
		list.__init__(s)
		s.append(x)
		s.append(y)
	
	@property
	def x(s):
		"""I'm the 'x' property."""
		return s[0]
	@x.setter
	def x(s,v):
		s[0] = v
	@x.deleter
	def x(s):
		del s[0]
	
	@property
	def y(s):
		"""I'm the 'y' property."""
		return s[1]
	@y.setter
	def y(s,v):
		s[1] = v
	@y.deleter
	def y(s):
		del s[1]
	
	def __add__(s, o):
		return Point(s[0]+o[0],s[1]+o[1])
	def __sub__(s, o):
		return Point(s[0]-o[0],s[1]-o[1])
	def __neg__(s):
		return Point(-s[0],-s[1])
	def __mul__(s, o):
		return Point(o*s[0],o*s[1])
	def __rmul__(s, o):
		return s*o
	def __div__(s, o):
		return Point(s[0]/o,s[1]/o)
	
	def __iadd__(s, o):
		s[0] += o[0]
		s[1] += o[1]
		return s
	def __isub__(s, o):
		s[0] -= o[0]
		s[1] -= o[1]
		return s
	def __imul__(s, o):
		s[0] *= o
		s[1] *= o
		return s
	def __idiv__(s, o):
		s[0] /= o
		s[1] /= o
		return s
	
	def length(s):
		return (s[0]**2 + s[1]**2)**0.5
	def direction(s):
		return atan2(-s.y,s.x)
	def unit(s):
		return s/s.length()


def frange(a1,a2=None,step=1):
	if a2 is None:
		start,end = 0,a1
	else:
		start,end = a1,a2
	while step*start < step*end:
		yield start
		start += step




T = int(raw_input())

for t in xrange(1,T+1):
	
	R,C,D = map(int, raw_input().split())
	mass = dd(int)
	for r in xrange(R):
		line = raw_input()
		for c,m in enumerate(line):
			mass[c,r] = int(m)
	#print R,C,len(mass)
	
	size = min(R,C)
	while True:
		if size<3:
			size = None
			break
		
		done = False
		span = size-1
		rad = span/2
		#print range(0,C-span)
		for sx in xrange(0,C-span):
			#print range(0,R-span)
			for sy in xrange(0,R-span):
				sp = Point(sx,sy)
				
				psum = Point(0,0)
				csum = Point(0,0)
				c = sp + Point(rad,rad)
				for dx in xrange(size):
					for dy in xrange(size):
						edgex = (dx==0 or dx==size-1)
						edgey = (dy==0 or dy==size-1)
						if edgex and edgey: continue
						
						p = sp + Point(dx,dy)
						m = mass[tuple(p)]
						psum += m*p
						csum += m*c
				#print size,sp,psum,csum
				if (psum-csum).length() < 0.0001:
					done = True
					break
			if done:
				break
		if done:
			break
		
		size -= 1
	
	
	if size is None:
		print 'Case #{x}: {y}'.format(x=t, y='IMPOSSIBLE')
	else:
		print 'Case #{x}: {y}'.format(x=t, y=size)




























































