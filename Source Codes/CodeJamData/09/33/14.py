import sys
from math import *

def solve(case, P, Q, R):
	R.sort()
	S = {}
	def find_solution(b, e):
		if (b, e) in S:
			return S[(b, e)]
		cells = [cell for cell in R if cell>=b and cell<=e]
		if len(cells)==0:
			return 0
		else:
			poss = [
				find_solution(b, cell-1)+
				find_solution(cell+1, e)+
				e-b
				for cell in cells
			]
		result = min(poss)
		S[(b, e)] = result
		return result
	print "Case #%d: %d" % (case, find_solution(1, P))


if __name__=='__main__':
	N = int(sys.stdin.readline().strip())
	for n in xrange(N):
		P, Q = tuple([int(val) for val in sys.stdin.readline().strip().split(' ')])
		R = [int(val) for val in sys.stdin.readline().strip().split(' ')]
		solve(n+1, P, Q, R)

