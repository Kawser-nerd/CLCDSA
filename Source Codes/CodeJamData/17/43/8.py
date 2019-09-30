import pycosat # installable via pip or from https://pypi.python.org/pypi/pycosat

def getSquaresHit(grid, laserRow, laserCol, laserVert):
	"""laserVert is a boolean variable for wheter or not the given laser should be pointed vertically (false is horizontal)
	Returns a (possibly empty) set of open squares hit by the laser in (row, col) form
	Or returns "bad" if the given orientation would destroy a laser"""
	# do down / right first
	if laserVert:
		changeVert = 1
		changeHoriz = 0
	else:
		changeVert = 0
		changeHoriz = 1
	squaresHit = set()
	pos = (laserRow + changeVert, laserCol + changeHoriz)
	while True:
		if pos[0] < 0 or pos[1] < 0 or pos[0] >= len(grid) or pos[1] >= len(grid[0]):
			# went off the grid --> done
			break
		elif grid[pos[0]][pos[1]] == "-" or grid[pos[0]][pos[1]] == "|":
			# hit a laser --> bad
			return "bad"
		elif grid[pos[0]][pos[1]] == "#":
			# hit a wall --> done
			break
		elif grid[pos[0]][pos[1]] == "/":
			# mirror --> change direction
			changeVert, changeHoriz = -changeHoriz, -changeVert
		elif grid[pos[0]][pos[1]] == "\\":
			changeVert, changeHoriz = changeHoriz, changeVert
		else:
			# empty square
			squaresHit.add(pos)
		pos = (pos[0] + changeVert, pos[1] + changeHoriz)

	# do up / left next
	if laserVert:
		changeVert = -1
		changeHoriz = 0
	else:
		changeVert = 0
		changeHoriz = -1
	pos = (laserRow + changeVert, laserCol + changeHoriz)
	while True:
		if pos[0] < 0 or pos[1] < 0 or pos[0] >= len(grid) or pos[1] >= len(grid[0]):
			# went off the grid --> done
			break
		elif grid[pos[0]][pos[1]] == "-" or grid[pos[0]][pos[1]] == "|":
			# hit a laser --> bad
			return "bad"
		elif grid[pos[0]][pos[1]] == "#":
			# hit a wall --> done
			break
		elif grid[pos[0]][pos[1]] == "/":
			# mirror --> change direction
			changeVert, changeHoriz = -changeHoriz, -changeVert
		elif grid[pos[0]][pos[1]] == "\\":
			changeVert, changeHoriz = changeHoriz, changeVert
		else:
			# empty square
			squaresHit.add(pos)
		pos = (pos[0] + changeVert, pos[1] + changeHoriz)

	return squaresHit


numInputs = int(input())

for i in range(numInputs):
	R, C = [int(num) for num in input().split(" ")]
	grid = []
	for r in range(R):
		grid.append(list(input()))
	laserNums = {} # mapping from numbers (1-indexed) to positions of lasers on the grid (0-indexed)
	openNums = {} # mapping from numbers (0-indexed) to open positions on the grid (0 indexed)
	lastLaserNum = 0
	lastOpenNum = -1
	for row in range(R):
		for col in range(C):
			if grid[row][col] == "-" or grid[row][col] == "|":
				lastLaserNum += 1
				laserNums[lastLaserNum] = (row, col)
			elif grid[row][col] == ".":
				lastOpenNum += 1
				openNums[lastOpenNum] = (row, col)
	numLasers = lastLaserNum
	numOpens = lastOpenNum + 1
	cnf = [] # vertical is true, horizontal is false
	for _ in range(numOpens):
		cnf.append([])
	impossible = False
	for laser in range(1, numLasers + 1):
		laserPos = laserNums[laser]
		hitsVert = getSquaresHit(grid, laserPos[0], laserPos[1], True)
		hitsHoriz = getSquaresHit(grid, laserPos[0], laserPos[1], False)
		if hitsVert == "bad" and hitsHoriz == "bad":
			# will hit another laser no matter how pointed, so the setup is impossible
			impossible = True
			break
		if hitsVert == "bad":
			# if pointed vertically, will hit a laser, so make sure it points horizontally
			cnf.append([-laser])
		if hitsHoriz == "bad":
			# if pointed horizontally, will hit a laser, so make sure it points vertically
			cnf.append([laser])
		for openSq in range(numOpens):
			openPos = openNums[openSq]
			if hitsVert != "bad" and openPos in hitsVert:
				cnf[openSq].append(laser)
			if hitsHoriz != "bad" and openPos in hitsHoriz:
				cnf[openSq].append(-laser)
	if impossible:
		print("Case #" + str(i + 1) + ": IMPOSSIBLE")
		continue

	soln = pycosat.solve(cnf)
	if soln == "UNSAT":
		# no solution
		print("Case #" + str(i + 1) + ": IMPOSSIBLE")
		continue
	if soln == "UNKNOWN":
		raise Exception("Couldn't solve SAT on input " + str(i))

	# otherwise, gave a solution
	for laser in range(1, numLasers + 1):
		laserPos = laserNums[laser]
		if laser in soln:
			# means that this laser should be pointed vertically
			grid[laserPos[0]][laserPos[1]] = "|"
		else:
			# -laser in soln, so point horizontally
			grid[laserPos[0]][laserPos[1]] = "-"

	print("Case #" + str(i + 1) + ": POSSIBLE")
	for rowNum in range(R):
		row = ""
		for el in grid[rowNum]:
			row = row + el
		print(row)
	