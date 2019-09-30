#!/usr/bin/python2.5

import sys
import math

sq2 = math.sqrt(2)

def incircle(x, y, R) :
	if (x > R): return False
	if (y > R): return False
	return x * x + y * y <= R * R

def  part(x1, y1, R):
	x3 = math.sqrt(R * R - y1 * y1)
	y3 = math.sqrt(R * R - x1 * x1)
	a = math.asin(y3 / R) -  math.asin(y1 / R)
	s = (a / 2 * R * R) - (R * R * math.sin(a) / 2)
	return s + (y3 - y1) * (x3 - x1) / 2
	

def findpart(x1, y1, x2, y2, R):

	x3 = math.sqrt(R * R - y1 * y1)
	y3 = math.sqrt(R * R - x1 * x1)

	s = part(x1, y1, R)

	if (y3 > y2):
		s -= part(x1, y2, R)

	if (x3 > x2):
		s -= part(x2, y1, R)

	#print "findpart =", s

	return s

def solve(R, t, r, g) :
	
	R2 = R - t

	S = math.pi * (R ** 2) / 4

	y = r

	while y < R2:
		x =  r
		while x < R2 :
			if (x * x + y * y > R2 * R2):
				break;

			if incircle(x + g, y + g, R2) :
				S -= g * g
			else:
				S -= findpart(x, y, x + g, y + g, R2)
			
			x += g + 2 * r
		
		y += g + 2 * r

	return (S * 4 ) / (math.pi * (R ** 2))

inputName = "test.in" if (len(sys.argv) < 2) else sys.argv[1]
#inputName = "A-small.in"

file = open(inputName, "r")
case_count = int(file.readline())

for case in range(case_count) :
	f, R, t, r, g = map(float, file.readline().split())

	ans = 0
	t = t + f
	g = g - 2 * f
	r = r + f

	#print R, t, r, g
	
	if (t >= R or g <= 0 or r * sq2 >= R - t) : 
		ans = 1
	else:
		ans = solve(R, t, r, g)


	print "Case #%s: %.6f" % (case + 1, ans)

