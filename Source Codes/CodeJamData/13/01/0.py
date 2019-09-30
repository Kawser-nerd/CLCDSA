#!/usr/bin/python3

'''

Google Code Jam 2013
Qualification Round
Problem A - Tic-Tac-Toe-Tomek

Notes:
	* pretty simple problem of just checking the board layout for winning conditions
	* basic procedure:
		if win('X'): result = 'X won'
		elif win('O'): result = 'Y won'
		elif present('.'): result = 'Game has not completed'
		else: result = 'Draw'
	* checking for a specific win:
		check all rows
		check all columns
		check 2 diagonals

'''

import sys
import time
import operator
from functools import reduce

timeit = 1
debugv = 0

def main():
	T = int(sys.stdin.readline())
	for case in range(1,T+1):
		doCase(case)

def win(grid, marker):
	# horizontal (the inner list comprehension is not simplified to grid[i], because we want to preserve the similarity with the vertical check, for possible future code-merging)
	for i in range(4):
		if reduce(operator.and_, [(m == marker) or (m == 'T') for m in [grid[i][j] for j in range(4)]], 1):
			return True
	
	# vertical
	for j in range(4):
		if reduce(operator.and_, [(m == marker) or (m == 'T') for m in [grid[i][j] for i in range(4)]], 1):
			return True
	
	# diagonals
	if reduce(operator.and_, [(m == marker) or (m == 'T') for m in [grid[i][i] for i in range(4)]], 1):
		return True
		
	if reduce(operator.and_, [(m == marker) or (m == 'T') for m in [grid[3-i][i] for i in range(4)]], 1):
		return True
	
	# <<< after reading some stuff about "reduce" being discouraged in python for lack of readabity, I'm considering perhaps I should have used more explicit loops
	
	return False

def present(grid, marker):
	for i in range(4):
		for j in range(4):
			if (grid[i][j] == marker):
				return True
	return False

def doCase(case):
	grid = []
	for i in range(4):
		grid.append(sys.stdin.readline()[0:4])
	
	sys.stdin.readline()
	
	if win(grid, 'X'):
		result = 'X won'
	elif win(grid, 'O'):
		result = 'O won'
	elif present(grid, '.'):
		result = 'Game has not completed'
	else:
		result = 'Draw'
	
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

