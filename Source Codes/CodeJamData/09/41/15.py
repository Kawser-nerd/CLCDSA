#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys

def max1(r):
	z=[i for i in range(len(r)) if r[i]==1]
	if(z==[]):
		return 0
	else:
		return max(z)

def solve(inp):
	inp = [max1(s) for s in inp]
	ans=0
	for i in range(len(inp)):
		z = min([q for q in range(len(inp)) if q >=i and inp[q] <= i])
		r = list(range(i,z))
		r.reverse()
		for j in r:
			inp[j], inp[j+1] = inp[j+1], inp[j]
			ans+=1
	return ans

rdln = sys.stdin.readline

T = int(rdln())

for t in range(T):
	N = int(rdln())
	print("Case #", t+1, ": ", solve([ [int(c) for c in rdln().strip()] for w in range(N)]), sep="")

