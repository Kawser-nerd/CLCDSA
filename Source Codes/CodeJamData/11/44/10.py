import sys

#file = open("d.test")
file = open("D-small-attempt1.in")
strWholeFile = file.read()
aStrLines = strWholeFile.split("\n")

nCases = int(aStrLines[0])
aStrLinesLeft = aStrLines[1:]

for nCase in range(1, nCases + 1):
	print >> sys.stderr, "On case " + str(nCase) + " of " + str(nCases)
	aStrLinesCur = aStrLinesLeft[0:2]
	aStrLinesLeft = aStrLinesLeft[2:]

	aStrToks = aStrLinesCur[0].split()
	nPlanets = int(aStrToks[0])
	nWormholes = int(aStrToks[1])
	
	matAdj = map(lambda foo: map(lambda bard: False, range(nPlanets)), range(nPlanets))
	
	aStrToks = aStrLinesCur[1].split()
	for tok in aStrToks:
		aStrPlanets = tok.split(",")
		i = int(aStrPlanets[0])
		j = int(aStrPlanets[1])
		matAdj[i][j] = True
		matAdj[j][i] = True
		
	lPathQueue = [[0]]
	lPathSoln = []
	
	while len(lPathSoln) == 0:
		#print "Path candidates: " + str(lPathQueue)
		lPathQueueNext = []
		
		for path in lPathQueue:
			aFAdj = matAdj[path[-1]]
			
			if aFAdj[1]:
				lPathSoln = lPathSoln + [path]
			else:
				for i in range(nPlanets):
					if aFAdj[i] and not i in path:
						lPathQueueNext = lPathQueueNext + [path + [i]]
						
		lPathQueue = lPathQueueNext
	
	nConquer = len(lPathSoln[0]) - 1
	nThreatenBest = 0
	
	for path in lPathSoln:
		aTfnThreaten = map(lambda foo: 0, range(nPlanets))
		nThreaten = 0
		
		for planet in path:
			if aTfnThreaten[planet] == 1:
				nThreaten -= 1
			aTfnThreaten[planet] = -1
			
			for i in range(nPlanets):
				if aTfnThreaten[i] == 0 and matAdj[planet][i]:
					aTfnThreaten[i] = 1
					nThreaten += 1
		
		if nThreaten > nThreatenBest:
			nThreatenBest = nThreaten
				
	print "Case #" + str(nCase) + ": " + str(nConquer) + " " + str(nThreatenBest)