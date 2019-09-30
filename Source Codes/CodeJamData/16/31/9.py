f = open('large1.in')
T = int(f.readline().strip())
# print T

for k in range(T):
	numParties = int(f.readline().strip())
	evac = []
	allSen = f.readline().split()
	#print allSen
	alpha = 65
	oneDict = {}
	for i in range(numParties):
		oneDict[chr(alpha)] = allSen[i]
		alpha+=1
	#print oneDict
	oneList = []
	totalSen = 0
	for i in range(numParties):
		oneList.append(int(allSen[i]))
		totalSen += int(allSen[i])
	#print oneList
	while (totalSen >= 2):
		newPair = ""
		for i in range(2):
			max_value = max(oneList)
			max_index = oneList.index(max_value)
			oneList[max_index] -= 1
			newAlpha = 65 + max_index
			newPair += chr(newAlpha)
			totalSen -= 1
			if totalSen == 2:
				break
		evac.append(newPair)
	#print evac
	print "Case #%d: %s" %(k+1, " ".join(evac))



