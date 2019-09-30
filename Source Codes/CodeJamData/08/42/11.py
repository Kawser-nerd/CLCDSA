#!/usr/bin/env python

def solve():
	N, M, A = [ int(i) for i in raw_input().split() ]

	for x in range(1, N + 1):
		for y in range(1, M + 1):
			if x * y < A:
				continue
			for a in range(0, x + 1):
				for b in range(0, y + 1):
					if x * y - a * b == A:
						return ' '.join(str(i) for i in (
							0, 0, x, b, a, y
							))

	return 'IMPOSSIBLE'

import psyco
psyco.full()

for case in range(int(raw_input())):
	print 'Case #%d: %s' % (case + 1, solve())
