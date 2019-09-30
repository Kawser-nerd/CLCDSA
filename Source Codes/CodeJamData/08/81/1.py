import sys
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return map(foo, raw_input().split())

def getm(x11, x12, x13, x21, x22, x23):
	a = x12 - x11
	b = x13 - x11
	c = x22 - x21
	d = x23 - x21
	return (a - c, b - d, x21 - x11)  
	

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	(x11, y11, x12, y12, x13, y13) = readarray(int) 
	(x21, y21, x22, y22, x23, y23) = readarray(int) 

	(m11, m12, b1) = getm(x11, x12, x13, x21, x22, x23)
	(m21, m22, b2) = getm(y11, y12, y13, y21, y22, y23)
	d = m11 * m22 - m12 * m21
	if d == 0:
		if (x11 == x21 and x12 == x22 and x13 == x23 and y11 == y21 and y12 == y22 and y13 == y23):
			print "Case #%d: %.6f %.6f" % (test + 1, x11, y11)
		else:
			print "Case #%d: No solution" % (test + 1)		
		continue
	d1 = m11 * b2 - b1 * m21
	d2 = b1 * m22 - m12 * b2
	p = 1.0 * d1 / d
	q = 1.0 * d2 / d
	p, q = q, p
	x = (x12 - x11) * p + (x13 - x11) * q + x11
	y = (y12 - y11) * p + (y13 - y11) * q + y11
	
	
	print "Case #%d: %.6f %.6f" % (test + 1, x, y) 
#	e1x = x12 - x11
#	e2x = 
