#!/usr/bin/env python

import fileinput

def readCase(f):
	return map(float,f.readline().split())

def printResult(i, out):
	print "Case #%d: %s" % (i+1, out)

def solve(C, F, X):
	rate = 2.0
	time = 0.0
	while True:
		if X / rate < C / rate + X / (rate + F):
			return time + X/rate
		time += C / rate
		rate += F

if __name__ == '__main__':
	f = fileinput.input()
	N = int(f.readline())
	for i in range(N):
		printResult(i,solve(*readCase(f)))