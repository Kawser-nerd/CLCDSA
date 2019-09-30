import copy
import collections

def isCorner(x,y):
	if (x,y) == (1,1):
		return True
	if (x,y) == (1,size):
		return True
	if (x,y) == (size,maxIndex):
		return True
	if (x,y) == (maxIndex, maxIndex):
		return True
	if (x,y) == (maxIndex, size):
		return True
	if (x,y) == (size,1):
		return True
	return False
	
def getEdgeIndex(x, y):
	if isCorner(x,y):
		return 0
	if x == 1:
		return 1
	if y - x + 1 == size:
		return 2
	if y == maxIndex:
		return 3
	if x == maxIndex:
		return 4
	if x - y + 1 == size:
		return 5
	if y == 1:
		return 6
	return 0
	
def IsInBoard(x,y):
	
	if x < 1:
		return False
	if y - x + 1 > size:
		return False
	if y > maxIndex:
		return False
	if x > maxIndex:
		return False
	if x - y + 1 > size:
		return False
	if y < 1:
		return False
	return True
		

def checkBridge(table, x, y):
	temp = table
	l = []
	q = collections.deque()
	q.append((x,y))
	cornerCount = 0
	temp[x][y] = 0
	l += [(x,y)]
	while len(q) > 0:
		cx, cy = q.popleft()
		if isCorner(cx, cy):
			cornerCount += 1
			if cornerCount >=2:
				for i in l:
					temp[i[0]][i[1]]  = 1
				return True
		for i in connect:
			nx, ny = cx + i[0], cy + i[1]
			if temp[nx][ny] == 1:
				q.append((nx, ny))
				temp[nx][ny] = 0
				l += [(nx,ny)]
				
	for i in l:
		temp[i[0]][i[1]] = 1
	return False

def checkFork(table, x, y):
	temp = table
	l = []
	q = collections.deque()
	q.append((x,y))
	edgeCount = 0
	edge = [0] * 7
	edge[0] = 1
	temp[x][y] = 0
	l += [(x,y)]
	while len(q) > 0:
		cx, cy = q.popleft()
		edgeIndex = getEdgeIndex(cx, cy)
		if edge[edgeIndex] == 0:
			edge[edgeIndex] = 1
			edgeCount += 1
			if edgeCount >=3:
				for i in l:
					temp[i[0]][i[1]]  = 1
				return True
		for i in connect:
			nx, ny = cx + i[0], cy + i[1]
			if temp[nx][ny] == 1:
				q.append((nx, ny))
				temp[nx][ny] = 0
				l += [(nx,ny)]
				
	for i in l:
		temp[i[0]][i[1]]  = 1
	return False

def checkRing(table, x, y):
	for i in connect:
		nx, ny = x + i[0], y + i[1]
		if IsInBoard(nx, ny) and table[nx][ny] == 0:
			if checkRing2(table, nx, ny):
				return True
	return False

def checkRing2(table, x, y):
	temp = table
	l = []
	q = collections.deque()
	q.append((x,y))
	temp[x][y] = 1
	l += [(x,y)]
	while len(q) > 0:
		cx, cy = q.popleft()
		if getEdgeIndex(cx, cy) > 0 or isCorner(cx, cy):
			for i in l:
				temp[i[0]][i[1]]  = 0
			return False
		for i in connect:
			nx, ny = cx + i[0], cy + i[1]
			if temp[nx][ny] == 0:
				q.append((nx, ny))
				temp[nx][ny] = 1
				l += [(nx,ny)]
	for i in l:
		temp[i[0]][i[1]]  = 0
	return True
	
	
connect = [[1,1], [0,1], [-1,0], [-1, -1], [0, -1], [1, 0]]

testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	size, mCount = [int (x) for x in raw_input().split(" ")]
	move = []
	for i in range(mCount):
		move += [[int (x) for x in raw_input().split(" ")]]
	maxIndex = size * 2 - 1
	table = []
	row = [0] * (maxIndex + 2)
	#print size, mCount
	for i in range(maxIndex + 2):
		table += [row[:]]
	for i in range(mCount):
		x,y = move[i]
		table[x][y] = 1
		
		bridge = checkBridge(table, x, y)
		fork = checkFork(table, x, y)
		ring = checkRing(table, x, y)
		win = False
		if bridge:
			ans += "bridge"
			win = True
		if fork:
			if win:
				ans += "-"
			ans += "fork"
			win = True
		if ring:
			if win:
				ans += "-"
			ans += "ring"
			win = True
		if win:
			ans += " in move " + str(i+1)
			break
	else:
		ans += "none"
	
	print (ans )
