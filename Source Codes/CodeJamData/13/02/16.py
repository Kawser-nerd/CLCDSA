from math import *

T = input()

def check(b):
	rm = [max(b[i]) for i in range(len(b))]
	cm = [max([b[j][i] for j in range(len(b))]) for i in range(len(b[0]))]

	for i in range(len(b)):
		for j in range(len(b[0])):
			if b[i][j] < rm[i] and b[i][j] < cm[j]:
				return False
	return True

for case in range(T):
	[n,m] = [int(y) for y in raw_input().strip().split()]
	#print n,m
	board = []
	for i in range(n):
		board.append([int(y) for y in raw_input().strip().split()])

	print "Case #%d: %s" % (case + 1, "YES" if check(board) else "NO")