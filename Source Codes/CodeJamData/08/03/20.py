#!/usr/bin/python
import math

def pyth(k, r):
	return   math.sqrt(r*r-k*k)
	
def corner(x1, y1, x2, y2, r):	#x1 < x2, y1 > y2
	tr = (x1 * (y1 - y2) + y2 * (x2 - x1))/2
	angle = math.atan(y1/x1) - math.atan(y2/x2)
	sl = r * r * angle / 2
	return sl - tr
	
	
def inside(x, y, r):
	return x*x + y*y <= r*r
	
def square(x, y, w, r):
	if not inside(x, y, r):
		return 0
	
	if inside(x+w, y+w, r):
		return w*w
	
	if inside(x+w, y, r) and inside(x, y+w, r):
		x2 = pyth(y+w,r)
		y2 = pyth(x+w,r)
		return w*w - (x+w-x2)*(y+w-y2) + corner(x2, y+w, x+w, y2, r)
	
	if inside(x+w, y, r):
		y2 = pyth(x+w, r)
		y3 = pyth(x, r)
		return w*(y2-y) + corner(x, y3, x+w, y2, r)
		
	if inside(x, y+w, r):
		x2 = pyth(y+w, r)
		x3 = pyth(y, r)
		return w*(x2-x) + corner(x2, y+w, x3, y, r)
	
	else:
		y2 = pyth(x, r)
		x2 = pyth(y, r)
		return corner(x, y2, x2, y, r)

def solve(f, R, t, w, g):
	OPEN = 'open'
	CLOSED = 'closed'
	
	t += f
	w += f
	g -= f*2
	if g <= 0:
		return 1.0
	r = R - t
	
	
	squarea = 0
	y = w
	while y <= r:
		x = w
		while x <= r:
			squarea += square(x, y, g, r)
			x += 2*w+g
		y += 2*w+g
		
	
	cut = squarea
	circle = math.pi*R*R/4
	return 1.0 - cut/circle

fin = open("c.in","r")
fout = open("c.out","w")

n = int(fin.readline())
for i in range(n):
	f, R, t, w, g = map(float, fin.readline().split())
	s = solve(f, R, t, w, g)
	print >> fout, "Case #%d: %.6f" % (i+1, s)
	print "Case #%d: %.6f" % (i+1, s)

fout.close()