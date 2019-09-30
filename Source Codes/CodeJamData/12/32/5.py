#

from math import *

T = int( raw_input() )

for tInput in xrange( 1, T+1 ):
	
	line = raw_input().split()
	D = float(line[0])
	N, A = int(line[1]), int(line[2])
	
	ts = [0]*N
	xs = [0]*N
	for i in xrange(N):
		line = raw_input().split()
		ts[i], xs[i] = float(line[0]), float(line[1])
	
	accelerations = map( float, raw_input().split() )
	
	print "Case #%d:" % tInput
	
	## B-small
	c = xs[0]
	if N == 1: v0 = 0
	else: v0 = (xs[1]-xs[0])/(ts[1]-ts[0])
	
	if v0 == 0:
		for a in accelerations:
			print sqrt(2*D/a)
	
	else:
		
		t2 = (D-c)/v0;
		
		for a in accelerations:
			t2star = (v0+sqrt(v0*v0+2*a*c))/a#
			if a < (2*t2*v0 + 2*c)/(t2*t2) or v0 > a*t2: print sqrt(2*D/a) # i.e. if t2star > t2
			else: print t2
	##
