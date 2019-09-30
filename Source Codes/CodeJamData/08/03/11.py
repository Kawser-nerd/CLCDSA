#!/usr/bin/env python2.5

import sys
from random import random
from math import floor, pi, sqrt
infile = open(sys.argv[1], 'rb')
numcases = int(infile.readline())


for case in xrange(1, numcases+1):
	vals = infile.readline().split()
	fly_r, outer_r, thickness, string_r, gap = float(vals[0]), float(vals[1]), float(vals[2]), float(vals[3]), float(vals[4])
	outer_r2 = outer_r*outer_r
	total_area = pi*outer_r2/4.0
	rim_hit2 = pow(outer_r - thickness - fly_r, 2)
	
	space = gap + 2*string_r
	x = string_r + fly_r 
	eff_gap = gap - 2*fly_r
	if eff_gap <= 0:
		print "Case #%d: 1.000000" % (case)
		continue
	interval = eff_gap/200
	holes = 0.0
	while x<outer_r-fly_r-thickness:
		y = string_r + fly_r
		while y<outer_r-fly_r-thickness:
			irad =  x*x + y*y
			if irad < rim_hit2:
				orad = (x+eff_gap)*(x+eff_gap) + (y+eff_gap)*(y+eff_gap)
				if orad <= rim_hit2:
					holes += eff_gap*eff_gap
				else:
					ymax = y+eff_gap
					xcurr = x+interval/2.0
					while xcurr < x+eff_gap and xcurr<outer_r-fly_r-thickness:
						ycalc = sqrt(rim_hit2 - xcurr*xcurr)
						if ycalc < ymax:
							if ycalc >y:
								holes += interval*(ycalc-y)
						else:
							holes += interval*eff_gap
						xcurr+=interval
			y+=space
		x += space
	print "Case #%d: %.6f" % (case, 1-holes/total_area)
		
		