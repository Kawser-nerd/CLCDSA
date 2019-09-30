import sys
import string
def getline():
	return sys.stdin.readline()[:-1]
def testcase():
	line = getline().split(' ')
	n = int(line[0])
	m = int(line[1])
	board = []
	for i in range(n):
		board.append(getline())
	#print board
	for i in range(min(n,m), 2, -1):
		#print i
		for j in range(n-i+1):
			for k in range(m-i+1):
				x = 0
				y = 0
				cx = j+j+i-1
				cy = k+k+i-1
				for s in range(j, j+i):
					borderx = (s == j) or (s == j+i-1)
					for t in range(k, k+i):
						bordery = (t == k) or (t == k+i-1)
						if borderx and bordery:
							continue
						x += int(board[s][t]) * (s+s-cx)
						y += int(board[s][t]) * (t+t-cy)
				if x == 0 and y == 0:
					#print i,j,k, x, y
					return '{0}'.format(i)
	return 'IMPOSSIBLE'
t = int(getline())
for i in range(t):
	print 'Case #{0}: {1}'.format(i+1, testcase())

