def reg(i,j,grid, boxes, toys):
	curBoxes = boxes[i][:]
	curToys = toys[j][:]
	#match if possible
	if curBoxes[0] == curToys[0]: # same type
		matches = min(curBoxes[1],curToys[1])
		curBoxes[1] -= matches
		curToys[1] -= matches
		if curBoxes[1] != 0: # left over boxes
			return matches + part(curBoxes, True, i+1, j+1, grid, boxes, toys)
		elif curToys[1] != 0: # left over toys
			return matches + part(curToys, False, i+1, j+1, grid, boxes, toys)
		else: # nothing left over (matched all of each)
			return matches + grid[i+1][j+1]
	else:
		return max(grid[i+1][j],grid[i][j+1])

def part(p,isBoxes,i,j,grid,boxes,toys):
	if i-isBoxes == len(boxes) or j-(not isBoxes) == len(toys):
		return 0
	if isBoxes: # extra boxes
		curBoxes = p
		curToys = toys[j][:]
		if curBoxes[0] == curToys[0]: # same type
			matches = min(curBoxes[1],curToys[1])
			curBoxes[1] -= matches
			curToys[1] -= matches
			if curBoxes[1] != 0: # left over boxes
				return matches + part(curBoxes, True, i, j+1, grid, boxes, toys)
			elif curToys[1] != 0: # left over toys
				return matches + part(curToys, False, i, j+1, grid, boxes, toys)
			else: # nothing left over (matched all of each)
				return matches + grid[i][j+1]
		else:
			return max(grid[i][j], part(curBoxes, True, i, j+1, grid, boxes, toys))
	else: # extra toys
		curBoxes = boxes[i][:]
		curToys = p
		if curBoxes[0] == curToys[0]: # same type
			matches = min(curBoxes[1],curToys[1])
			curBoxes[1] -= matches
			curToys[1] -= matches
			if curBoxes[1] != 0: # left over boxes
				return matches + part(curBoxes, True, i+1, j, grid, boxes, toys)
			elif curToys[1] != 0: # left over toys
				return matches + part(curToys, False, i+1, j, grid, boxes, toys)
			else: # nothing left over (matched all of each)
				return matches + grid[i+1][j]
		else:
			return max(grid[i][j], part(curToys, False, i+1, j, grid, boxes, toys))


inFile = open('C-large.in','r')
outFile = open('box.out','w')
T = int(inFile.readline())
for n in range(1,T+1):
	N,M = tuple([int(x) for x in inFile.readline().split()])
	boxes = [0 for i in range(N)]
	toys = [0 for i in range(M)]
	b = [int(x) for x in inFile.readline().split()]
	for i in range(0,len(b),2):
		boxes[i//2] = [b[i+1],b[i]]
	t = [int(x) for x in inFile.readline().split()]
	for i in range(0,len(t),2):
		toys[i//2] = [t[i+1],t[i]]
		
	grid = [[0 for j in range(M+1)] for i in range(N+1)]
	for i in range(N-1,-1,-1):
		for j in range(M-1,-1,-1):
			grid[i][j] = reg(i,j,grid, boxes, toys)
	
	#print(boxes, toys)
	print('Case #'+str(n)+': '+str(grid[0][0]))
	outFile.write('Case #'+str(n)+': '+str(grid[0][0])+'\n')
