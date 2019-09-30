
file = open("c-small-attempt2.in")
#file = open("c.test")
strWholeFile = file.read()
aStrLines = strWholeFile.split("\n")

nCases = int(aStrLines[0])
aStrLinesLeft = aStrLines[1:]

for nCase in range(1, nCases + 1):
	aStrLinesCur = aStrLinesLeft[0:3]
	aStrLinesLeft = aStrLinesLeft[3:]
	
	aStrToks = aStrLinesCur[0].split()
	nPoints = int(aStrToks[0])
	nWalls = int(aStrToks[1])
	
	aryFace = []
	aryFace.append(range(1, nPoints + 1))
	
	aWallX = map(lambda str: int(str), aStrLinesCur[1].split())
	aWallY = map(lambda str: int(str), aStrLinesCur[2].split())
	
	for i in range(0, nWalls):
		aryFaceNext = []
		for face in aryFace:
			if aWallX[i] in face and aWallY[i] in face:
				iX = face.index(aWallX[i])
				iY = face.index(aWallY[i])
				
				if iX > iY:
					temp = iX
					iX = iY
					iY = temp
				
				faceNewA = face[iX:iY+1]
				faceNewB = face[iY:] + face[:iX+1]
				
				aryFaceNext.append(faceNewA)
				aryFaceNext.append(faceNewB)
			else:
				aryFaceNext.append(face)
		
		aryFace = aryFaceNext
	
	aryColors = (nPoints + 1) * [0]
	aryColors[0] = -1
	nFewest = nPoints + 1
	iFaceFewest = -1
	
	#print "All faces: " + str(aryFace)
	
	for face in aryFace:
	
		ptsLeft = len(face)
		if ptsLeft < nFewest and ptsLeft > 0:
			nFewest = ptsLeft
			iFaceFewest = aryFace.index(face)
			
	nColors = nFewest
	
	i = 1
	for point in aryFace[iFaceFewest]:
		aryColors[point] = i
		i += 1
	
	aryFace.remove(aryFace[iFaceFewest])

	
	while 0 in aryColors:
		#print "Colors so far: " + str(aryColors)
		#print "Faces left: " + str(aryFace)
		slackLeast = nPoints + 5
		iSlackLeast = -1
		ptsUncoloredLeast = slackLeast
		
		for face in aryFace:
			#print "Checking face " + str(face)
			ptsUncolored = filter(lambda pt: aryColors[pt] == 0, face)
			
			if len(ptsUncolored) == 0:
				#print "It's fine; early exit"
				continue
				
			colorsInFace = set(filter(lambda col: col != 0, map(lambda pt: aryColors[pt], face)))
			#print "Colors in face: " + str(colorsInFace)
			slack = len(ptsUncolored) - (nColors - len(colorsInFace))
			#print "Face " + str(face) + " has slack: " + str(slack)
			
			if slack <= slackLeast and len(ptsUncolored) < ptsUncoloredLeast:
				slackLeast = slack
				ptsUncoloredLeast = len(ptsUncolored)
				iSlackLeast = aryFace.index(face)
				
		face = aryFace[iSlackLeast]
		#print "Picked face " + str(face)
		aryFace.remove(face)
		ptsUncolored = filter(lambda pt: aryColors[pt] == 0, face)
			
		colorsInFace = set(filter(lambda col: col != 0, map(lambda pt: aryColors[pt], face)))
		colorsNeeded = set(range(1, nColors + 1)) - colorsInFace
		for pt in ptsUncolored:
			if len(colorsNeeded) > 0:
				aryColors[pt] = colorsNeeded.pop()
			else:
				aryColors[pt] = 1
			#print "Colored " + str(pt) + " to be " + str(aryColors[pt])
		

	print "Case #" + str(nCase) + ": " + str(nFewest)
	strRes = ""
	for c in aryColors:
		if c != -1:
			if strRes != "":
				strRes = strRes + " "
			strRes = strRes + str(c)
		
	print strRes