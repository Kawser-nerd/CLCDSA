#!/usr/bin/python2.5

import sys
import math

def converttime(t):
	A, B = map(int, t.split(":"))
	return A * 60 + B

def solve(TA, TB):
	#print  TA, TB

	ALL = [(A, B, 0) for A, B in TA] + [(A, B, 1) for A, B in TB]
	ALL.sort(cmp=lambda x, y : x[1] - y[1])

	#print  ALL
	ans = [0, 0]
	wait = [[], []]
	for (A, B, s) in ALL:

		for i in range(len(wait[s])):
			if wait[s][i] <= A:
				#print  "found", wait, i
				wait[s].pop(i);
				#print  "wait = ", wait
				break;
		else:
			ans[s] += 1

		wait[1 - s].append(B)
		wait[1 - s].sort(reverse=True)

	#print  wait
	#print  ans
	return ans[0], ans[1]


inputName = "test.in" if (len(sys.argv) < 2) else sys.argv[1]
#inputName = "A-small.in"
#inputName = "B-small-attempt0.in"

f = open(inputName, "r")
case_count = int(f.readline())

for case in range(case_count) :
	T = int(f.readline().strip("\n "))
	A, B =  map(int, f.readline().split())
	
	TA = []
	for i in range(A):
		e = f.readline().split()
		TA.append((converttime(e[0]), converttime(e[1]) + T))
		
	TB = []
	for i in range(B):
		e = f.readline().split()
		TB.append((converttime(e[0]), converttime(e[1]) + T))

	ans = solve(TA, TB)


	print  "Case #%s: %s %s" % (case + 1, ans[0], ans[1])

