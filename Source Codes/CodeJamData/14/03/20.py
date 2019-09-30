#!/usr/bin/env python

import fileinput

def readCase(f):
	return map(int,f.readline().split())

def printResult(i, out):
	print "Case #%d:" % (i+1)
	print out

def solve(r, c, m):

	space = r * c - m
	board = [['*' for i in range(c)] for i in range(r)]

	if space == 1:
		board[0][0] = 'c'
		return drawBoard(board)
		
	if r == 1:
		return 'c' + '.' * (c - m - 1) + '*' * m
	if c == 1:
		return ('c\n' + '.\n' * (r - m - 1) + '*\n' * m)[:-1]

	if space < 4 or space == 5 or space == 7:
		return "Impossible"

	if r == 2:
		if m % 2 == 0 and m/2 < c-1:
			return 'c' + '.' * (c - m/2 - 1) + '*' * (m/2) + '\n' + \
			             '.' * (c - m/2) + '*' * (m/2)
		return "Impossible"

	if c == 2:
		if m % 2 == 0 and m/2 < r-1:
			return ('c.\n' + '..\n' * (r - m/2 - 1) + '**\n' * (m/2))[:-1]
		return "Impossible"

	x = 0
	while space >= 2 and x < r:
		board[x][0] = '.'
		board[x][1] = '.'
		x += 1
		space -= 2

	if space == 0:
		return drawBoard(board)
	if space == 1:
		board[x-1][0] = '*'
		board[x-1][1] = '*'
		board[0][2] = '.'
		board[1][2] = '.'
		board[2][2] = '.'
		return drawBoard(board)

	y = 2
	while y < c:
		if space == 0:
			return drawBoard(board)

		if space == 1:
			board[r-1][y-1] = '*'
			board[0][y] = '.'
			board[1][y] = '.'
			if y == 2:
				board[r-1][y-2] = '*'
				board[2][y] = '.'
			return drawBoard(board)

		if space <= r:
			for i in range(space):
				board[i][y] = '.'
			return drawBoard(board)

		for i in range(r):
			board[i][y] = '.'
		y += 1
		space -= r

	assert False

def drawBoard(board):
	return 'c' + '\n'.join([''.join(row) for row in board])[1:]

if __name__ == '__main__':
	f = fileinput.input()
	N = int(f.readline())
	for i in range(N):
		printResult(i,solve(*readCase(f)))
