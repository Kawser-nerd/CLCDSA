#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import math

def best3(a,b,c):
	(ax,ay,ar) = a
	(bx,by,br) = b
	(cx,cy,cr) = c
	return(max(ar,(math.sqrt( (bx-cx)**2 + (by-cy)**2)+float(br)+float(cr))/2.0))

rdln = sys.stdin.readline

C = int(rdln())

for c in range(C):
	N = int(rdln())
	p = [ [int(x) for x in rdln().split()] for w in range(N)]
	ans=0.0
	if N==1:
		ans=p[0][2]
	elif N==2:
		ans=max(p[0][2], p[1][2])
	else:
		assert(N==3)
		ans = min(best3(p[0], p[1], p[2]), best3(p[1], p[2], p[0]), best3(p[2], p[0], p[1]))
	print("Case #", c+1, ": ", ans, sep="")

