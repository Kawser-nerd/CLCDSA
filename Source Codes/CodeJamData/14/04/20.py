#!/usr/bin/env python

import fileinput

def readCase(f):
	f.readline()
	return map(float,f.readline().split()), map(float,f.readline().split())

def printResult(i, out):
	print "Case #%d: %s" % (i+1, out)

def solve(naomi, ken):
	naomi.sort()
	ken.sort()
	return "%d %d" % (solveDeceitful(list(naomi), list(ken)), \
						    solveWar(list(naomi), list(ken)))

def solveWar(naomi, ken):
	while len(naomi) and naomi[0] < ken[-1]:
		n = naomi.pop(0)
		ken.pop(next(index for index, value in enumerate(ken) if value > n))
	return len(naomi)

def solveDeceitful(naomi, ken):
	delay = 0
	score = 0
	while len(naomi):
		if naomi[0] < ken[0]:
			naomi.pop(0)
			ken.pop()
		else:
			score += 1
			ken.pop(0)
			naomi.pop(0)

	return score

if __name__ == '__main__':
	f = fileinput.input()
	N = int(f.readline())
	for i in range(N):
		printResult(i,solve(*readCase(f)))