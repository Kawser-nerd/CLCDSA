#!/usr/bin/env python3

import sys
import math
from functools import reduce

lines = [ l.strip() for l in sys.stdin.readlines() ]

T = int(lines[0])
i = 1
for t in range(T):
	N,K = map(int, lines[i].split(' '))
	i += 1
	U = float(lines[i])
	i += 1
	P = list(map(float, lines[i].split(' ')))
	i += 1

	P.sort()
	j = 0
	while j < N and U > 0.000000000001:
		while j < N-1 and P[j] == P[j+1]:
			j += 1
		target = P[j+1] if j < N-1 else 1
		required = (target-P[j])*(j+1)
		if required <= U:
			U -= required
			P[0:j+1] = [target]*(j+1)
		else:
			target = P[j] + U/(j+1)
			U = 0
			P[0:j+1] = [target]*(j+1)
		#print(j, U)
	#print(P)
	print("Case #%d: %f" % (t+1, reduce(lambda x, y: x * y, P, 1.0)))


