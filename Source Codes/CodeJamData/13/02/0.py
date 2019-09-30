#!/usr/bin/env python

'''

Google Code Jam 2013
Qualification Round
Problem B - Lawnmower

Notes:
	* all pattern cells for a given mower path must be <= the mower height for that path
	* cutting a given cell x to the required height will require that either:
		* all cells on the horizontal path through cell x are <= cell x
		* all cells on the vertical   path through cell x are <= cell x
	* if one of those conditions holds for cell x, then it's possible to get that cell to the correct height with the appropriate path
	* if that holds for all cells, then the pattern is possible, otherwise it's impossible
	* if we consider N and M to both be the same (maximum limit)...
		* the check for a single cell is O(N)
		* the check for all cells is O(N**3)
		* but we have maximum limits, so in number terms...
		* 100**3 = 1000000
		* this is very doable

'''

import sys
import time

timeit = 1
debugv = 0

def main():
	T = int(sys.stdin.readline())
	for case in range(1,T+1):
		doCase(case)

def doCase(case):
	N, M = [int(n) for n in sys.stdin.readline().split()]
	lawn = []
	for i in range(N):
		row = [int(n) for n in sys.stdin.readline().split()]
		if len(row) != M:
			raise Exception("incorrect line length")
		lawn.append(row)
	
	# if I knew python better, I might write the following loop to break out early
	
	lawn_possible = 1
	for i in range(N):
		for j in range(M):
			row_possible = 1
			for k in range(N):
				if lawn[k][j] > lawn[i][j]:
					row_possible = 0
			col_possible = 1
			for k in range(M):
				if lawn[i][k] > lawn[i][j]:
					col_possible = 0
			if not (row_possible or col_possible):
				lawn_possible = 0
	
	result = 'YES' if lawn_possible else 'NO'
	
	debug("{}\n".format(result))
	sys.stdout.write("Case #{}: {}\n".format(case, result))


def debug(m):
	if debugv:
		sys.stderr.write(m)

if __name__ == '__main__':
	startTime = time.clock()
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))

