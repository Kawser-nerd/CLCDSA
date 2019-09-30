#!/usr/bin/env python3

import sys
import math

lines = [ l.strip() for l in sys.stdin.readlines() ]

def circle(r):
	return math.pi *r*r

def height(heights, K):
	s = []
	for h in heights:
		s += [2*math.pi*h[0]*h[1]]
	s.sort(reverse=True)
	#print("Poi prendo " + str(s[0:K]))
	return sum(s[0:K])

T = int(lines[0])
i = 1
for t in range(T):
	N,K = map(int, lines[i].split(' '))
	i += 1

	res = 0

	pan = []
	
	for j in range(N):
		r,h = map(int, lines[i].split(' '))
		i += 1
		
		pan += [[r,h]]

	pan.sort(reverse=True)

	for j in range(N-K+1):
		base = circle(pan[j][0])
		altezza = height(pan[(j+1):], K-1) + 2*math.pi*pan[j][0]*pan[j][1]
		#print("altezza %f" % altezza)
		area = base + altezza
		#if area > res:
		#	print("Prendo %d" % j)
		res = max(res, area)

	#print(pan)

	print("Case #%d: %f" % (t+1, res))
