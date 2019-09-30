#!/usr/bin/python

from math import fabs

cases = int(raw_input())

for c in xrange(1, cases + 1):
	ns = int(raw_input())
	x = []
	y = []
	z = []
	p = []
	
	min_value = 0
	ship1 = -1
	ship2 = -1
	
	if ns == 1:
		print "Case #%d: 0.000000" % c
		continue
	
	for i in xrange(ns):
		xs, ys, zs, ps = raw_input().split()
		xa = int(xs)
		ya = int(ys)
		za = int(zs)
		pa = int(ps)
		x.append(int(xs))
		y.append(int(ys))
		z.append(int(zs))
		p.append(int(ps))
		
		for j in xrange(i+1):
			#print "Testing ship %d against ship %d" % (i, j)
			xb = x[j]
			yb = y[j]
			zb = z[j]
			pb = p[j]
			value = (fabs(xb-xa) + fabs(yb-ya) + fabs(zb-za))/float((pa+pb))
			#print "Got value %f" % value
			if value > min_value:
				min_value = value
				ship1 = i
				ship2 = j
	
	#print "Further apart ships are %d and %d" % (ship1, ship2)
	#print "Distance is %d" % min_value
	
	totalpf = float(p[ship1]) + float(p[ship2])
	scale = float(p[ship1])/float(totalpf)
	#print "xship2 %f xship1 %f scale %f" % (x[ship2], x[ship1], scale)
	cruiserx = (x[ship2]-x[ship1])*scale + x[ship1]
	cruisery = (y[ship2]-y[ship1])*scale + y[ship1]
	cruiserz = (z[ship2]-z[ship1])*scale + z[ship1]
	#print "Cruiser goes at %f %f %f" % (cruiserx, cruisery, cruiserz)
	
	power = (fabs(x[ship2] - cruiserx) + fabs(y[ship2] - cruisery)
		+ fabs(z[ship2] - cruiserz))/p[ship2]
	
	print "Case #%d: %8.6f" % (c, power)