#!/usr/bin/python

import sys
from hopcroftkarp import HopcroftKarp

if len(sys.argv) != 2:
	print "usage: ./a.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

def print_board(board):
	ret = ''
	N = len(board)
	for i in xrange(N):
		for j in xrange(N):
			ret += board[i][j]
		ret += '\n'
	print ret[:-1]

def solve(board):
	N = len(board)
	row = [True] * N
	col = [True] * N
	diag = [True] * (2 * N - 1)
	rdiag = [True] * (2 * N - 1)
	for i in xrange(N):	#init flag arrays
		for j in xrange(N):
			if board[i][j] in ['x', 'o']:
				row[i] = False
				col[j] = False
			if board[i][j] in ['+', 'o']:
				diag[i + j] = False
				rdiag[i - j + N - 1] = False
	for j in xrange(N):
		i = 0
		if diag[i + j] and rdiag[i - j + N - 1]:
			if board[i][j] == 'x':
				board[i][j] = 'o'
			else:
				board[i][j] = '+'
			diag[i + j] = rdiag[i - j + N - 1] = False
	for j in xrange(N):
		i = N - 1
		if diag[i + j] and rdiag[i - j + N - 1]:
			board[i][j] = '+'
			diag[i + j] = rdiag[i - j + N - 1] = False
	x = y = 0
	if not row[0]:
		for j in xrange(N):
			if board[0][j] in ['o', 'x']:
				y = j
				break
	for diff in xrange(N):
		xx = (x + diff) % N
		yy = (y + diff) % N
		if board[xx][yy] == '.':
			board[xx][yy] = 'x'
		elif board[xx][yy] == '+':
			board[xx][yy] = 'o'
	return

def solve_large(board):
	N = len(board)
	row = [True] * N
	col = [True] * N
	diag = [True] * (2 * N - 1)
	rdiag = [True] * (2 * N - 1)
	for i in xrange(N):	#init flag arrays
		for j in xrange(N):
			if board[i][j] in ['x', 'o']:
				row[i] = False
				col[j] = False
			if board[i][j] in ['+', 'o']:
				diag[i + j] = False
				rdiag[i - j + N - 1] = False
	#construct bipartite graph
	graph = {}
	mid = N - 1
	for i in xrange(2 * N - 1):
		upper_bound = mid - abs(i - mid)
		edges = set()
		for j in xrange(i % 2, upper_bound + 1, 2):
			edges.add('b' + str(mid - j))
			edges.add('b' + str(mid + j))
		graph[i] = edges
	#black out already used places for '+' (or 'o')
	for i in xrange(2 * N - 1):
		if not diag[i]:
			del graph[i]
		if not rdiag[i]:
			for node in graph:
				graph[node].discard('b' + str(i))
	#get maximum matching
	max_matching = HopcroftKarp(graph).maximum_matching()
	for x in max_matching:
		if type(x) == int:
			continue
		rdiag_no = int(x[1:])
		diag_no = max_matching[x]
		i = (diag_no + rdiag_no + 1 - N) / 2
		j = diag_no - i
		if board[i][j] == '.':
			board[i][j] = '+'
		elif board[i][j] == 'x':
			board[i][j] = 'o'
		else:
			print 'maximum matching put + to an already o or + place, exitting...'
			exit()
		diag[diag_no] = rdiag[rdiag_no] = False
	#now put x to the board
	for i in xrange(N):
		if row[i]:
			for j in xrange(N):
				if col[j]:
					if board[i][j] == '.':
						board[i][j] = 'x'
					elif board[i][j] == '+':
						board[i][j] = 'o'
					else:
						print 'try to put x to an already o or x place, exitting...'
						exit()
					row[i] = col[j] = False
					break
	return

def print_ret(board, ori_board):
	N = len(board)
	fashion = 0
	model_num = 0
	models = []
	for i in xrange(N):
		for j in xrange(N):
			if board[i][j] in ['+', 'x', 'o']:
				fashion += 1
				if board[i][j] == 'o':
					fashion += 1
				if board[i][j] != ori_board[i][j]:
					model_num += 1
					models.append((board[i][j], i + 1, j + 1))	
	ret = "%d %d" % (fashion, model_num)
	for i in xrange(model_num):
		ret += "\n%s %d %d" % models[i]
	return ret

def count_fashion(board):
	N = len(board)
	fashion = 0
	for i in xrange(N):
		for j in xrange(N):
			if board[i][j] in ['+', 'x']:
				fashion += 1
			elif board[i][j] == 'o':
				fashion += 2
	return fashion

def validate(board):
	N = len(board)
	row = [True] * N
	col = [True] * N
	diag = [True] * (2 * N - 1)
	rdiag = [True] * (2 * N - 1)
	for i in xrange(N):	#init flag arrays
		for j in xrange(N):
			if board[i][j] in ['x', 'o']:
				if not (row[i] and col[j]):
					return False
				row[i] = col[j] = False
			if board[i][j] in ['+', 'o']:
				if not (diag[i + j] and rdiag[i - j + N - 1]):
					return False
				diag[i + j] = rdiag[i - j + N - 1] = False
	return True

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		line = f.readline()
		N, M = [int(x) for x in line.split(' ')]
		board = []
		ori_board = []
		for j in xrange(N):
			board.append(['.'] * N)
			ori_board.append(['.'] * N)
		for j in xrange(M):
			line = f.readline().strip('\n')
			tmp = line.split(' ')
			v = tmp[0]
			x = int(tmp[1]) - 1
			y = int(tmp[2]) - 1
			board[x][y] = v
			ori_board[x][y] = v
		solve_large(board)
		if not validate(board):
			print 'something went wrong'
			exit()
		ret = print_ret(board, ori_board)
		#print_board(ori_board)
		#print ''
		#print_board(board)
		#print ''
		#if i > 1:
		#	exit()
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
