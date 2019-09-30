f = open('large2.in')
T = int(f.readline().strip())
# print T

for k in range(T):
	case = f.readline().split()
	B = int(case[0])
	M = int(case[1])
	# print B
	# print M
	if (M > (2**(B-2)) ):
		print "Case #%d: IMPOSSIBLE" %(k+1)
		continue
	print "Case #%d: POSSIBLE" %(k+1)
	matrix = []
	for i in range(B):
		oneLine = []
		for j in range(B):
			oneLine.append("0")
		matrix.append(oneLine)
	if (M > 0):
		M -= 1
		matrix[0][B-1] = "1"
	# print matrix
	totalPossible = 1
	lastIdx = 1
	for i in range(B-2):
		currentIdx = B-i-2
		if (M == 0):
			lastIdx = currentIdx + 1
			break
		if (M >= totalPossible):
			M -= totalPossible
			totalPossible *= 2
			otherIdx = currentIdx
			while (otherIdx < B-1):
				otherIdx+=1
				matrix[currentIdx][otherIdx] = "1"
		else:
			otherIdx = currentIdx
			while (otherIdx < B-1):
				otherIdx += 1
				totalPossible /= 2
				if (totalPossible == 0):
					totalPossible = 1
				# print totalPossible
				if (M >= totalPossible):
					M -= totalPossible
					matrix[currentIdx][otherIdx] = "1"
			lastIdx = currentIdx
			break
	while (lastIdx < B-1):
		matrix[0][lastIdx] = "1"
		lastIdx += 1
	# print matrix
	for line in matrix:
		# print line
		print "".join(line)

	# print "Case #%d: %s" %(k+1, " ".join(evac))



