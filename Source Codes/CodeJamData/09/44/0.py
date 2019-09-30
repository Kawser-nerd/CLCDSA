#!/usr/bin/env python2.6
import os, sys, re, math
stdin = sys.stdin

class Circle(object):
	def __init__(self, x=0, y=0, r=1):
		self.x = x
		self.y = y
		self.r = r

def solve(circles):
	if len(circles) == 1:
		return circles[0].r
		
	if len(circles) == 2:
		return max(c.r for c in circles)

	assert len(circles) <= 3
	
	best = 1e20
	
	for a in range(3):
		R = circles[a].r
		
		B = [circles[i] for i in range(3) if i != a]
		assert len(B) == 2
		R = max(R, 
			(math.sqrt((B[0].x - B[1].x)**2 + (B[0].y - B[1].y)**2) + B[0].r + B[1].r) / 2.0)
		
		best = min(best, R)

	return best

def main():
	T = int(stdin.readline())
	for cs in range(1, T+1):
		N = int(stdin.readline())
		
		circles = []
		for each in range(N):
			x, y, r = map(float, stdin.readline().split())
			circles.append(Circle(x, y, r))

		print 'Case #%d: %.15g' % (cs, solve(circles))

main()
