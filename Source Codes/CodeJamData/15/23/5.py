#!/usr/bin/python

import sys
from fractions import Fraction
import numpy as np

def solve(data):
	start = []
	# speed = []
	circle = []
	for d in data:
		for i in range(d[1]):
			start.append(d[0])
			circle.append(d[2]+i)
			# speed.append(Fraction(1,d[2]+i))
	N = len(start)

	def encounters(z):
		counter = 0
		for s,c in zip(start, circle):
			gap = (z - Fraction(360-s, 360)*c)/c
			counter_plus = int(gap+1)-1
			# print 'sp', counter_plus, gap, s, c
			# if counter_plus == gap:
			# 	if dc <= c:
			# 		counter_plus -= 1
			counter += abs(counter_plus)
		return counter

	min_encounter = N

	for s,c in zip(start, circle):
		z = Fraction(360-s, 360)*c
		# t = encounters(z)
		# print 'encounters', z, t, start, circle
		min_encounter = min(min_encounter, encounters(z))

	return min_encounter

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		N = int(sys.stdin.readline())
		data = [map(int, sys.stdin.readline().split()) for i in range(N)]
		print "Case #{}: {}".format(t+1, solve(data))