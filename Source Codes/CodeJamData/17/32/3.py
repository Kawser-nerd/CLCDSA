#!/usr/bin/env python3

import sys
import math

lines = [ l.strip() for l in sys.stdin.readlines() ]

T = int(lines[0])
i = 1
for t in range(T):
	Ac,Aj = map(int, lines[i].split(' '))
	A = [Ac,Aj]
	i += 1

	spans = []

	T = [720,720]

	for k in range(2):
		for j in range(A[k]):
			a,b = map(int, lines[i].split(' '))
			i += 1
			spans += [[a,b,k]]
			T[k] -= b-a

	spans.sort()
	first = spans[0]
	spans += [[first[0]+24*60,first[1]+24*60,first[2]]]

	#print(spans)

	sol = 0

	fillable = [[],[]]
	for j in range(Ac+Aj):
		if spans[j][2] == spans[j+1][2]:
			fillable[spans[j][2]] += [spans[j+1][0] - spans[j][1]]
			sol += 2
		else:
			sol += 1
	fillable[0].sort()
	fillable[1].sort()

	#print(fillable)

	for k in range(2):
		for j in fillable[k]:
			if j <= T[k]:
				T[k] -= j
				sol -= 2
			else:
				break
	
	print("Case #%d: %d" % (t+1, sol))

