#!/usr/bin/python2.5

import sys
import math

def solve1(Engines, Que):
	m = [0] * len(Engines)
	n = 0
	while (len(Que) > 0):
		q = Que.pop(0)
		if (m[Engines[q]] == 0): 
			m[Engines[q]] = 1
			n = n + 1
			if (n == len(Engines)):
				Que.insert(0, q)
				return
	return

def solve(Engines, Que):
	if len(Que) == 0:
		return 0
	n = 0
	while len(Que) > 0:
		solve1(Engines, Que)
		#print Que
		n = n + 1
	return n - 1

	

inputName = "test.in" if (len(sys.argv) < 2) else sys.argv[1]
#inputName = "A-small.in"

f = open(inputName, "r")
case_count = int(f.readline())

for case in range(case_count) :
	S = int(f.readline())
	Engines = []
	for i in range(S):
		Engines.append(f.readline().strip(" \n"))
	Q = int(f.readline())
		
	Que = []
	for i in range(Q):
		Que.append(f.readline().strip(" \n"))
	
	Engines = dict(zip(Engines, range(S)))
	
	#print S, Engines, Q, Que

	res = solve(Engines, Que)

	print "Case #%s: %s" % (case + 1, res)

