import sys
import math
c=0
phi = (1+5**.5)/2
for line in sys.stdin:
	if (c != 0):
		tot = 0
		strline = [int(i) for i in line.strip().split(' ')]
		(A1,A2,B1,B2) = (strline[0],strline[1],strline[2],strline[3])
		for a in range(A1,A2+1):
			phihigh = math.ceil(phi*a)
			philow = math.floor(a/phi)
			tot += max(0,min(philow,B2)-B1+1)
			tot += max(0,B2-max(B1,phihigh)+1)
		print "Case #%d: %d" % (c,tot)
	c += 1
