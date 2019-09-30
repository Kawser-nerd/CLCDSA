f = open('large3.in')
T = int(f.readline().strip())
# print T

for t in range(T):
	case = f.readline().split()
	J = int(case[0])
	P = int(case[1])
	S = int(case[2])
	K = int(case[3])
	if K >= S:
		K = S
	total = 0
	allList = []
	for j in range(J):
		startNum = j+1 + (K-1)*j
		if (startNum) > S:
			startNum = ((startNum-1)%S) + 1
		for p in range(P):
			oneList = []
			oneList.append(str(j+1))
			oneList.append(str(p+1))
			for k in range(K):
				finalList = list(oneList)
				finalList.append(str(startNum))
				allList.append(finalList)
				total += 1
				startNum += 1
				if (startNum) > S:
					startNum = 1
	# CHECK
	# JP = {}
	# JS = {}
	# PS = {}
	# for i in allList:
	# 	jp = i[0] + i[1]
	# 	if jp in JP:
	# 		JP[jp] += 1
	# 	else:
	# 		JP[jp] = 1
	# 	js = i[0] + i[2]
	# 	if js in JS:
	# 		JS[js] += 1
	# 	else:
	# 		JS[js] = 1
	# 	ps = i[1] + i[2]
	# 	if ps in PS:
	# 		PS[ps] += 1
	# 	else:
	# 		PS[ps] = 1
	
	# print total
	# for key, value in JP.iteritems():
	# 	if value > K:
	# 		print "WRONG"
	# for key, value in JS.iteritems():
	# 	if value > K:
	# 		print "WRONG"
	# for key, value in PS.iteritems():
	# 	if value > K:
	# 		print "WRONG"
	# if total != len(allList):
	# 	print "WRONG"
	# print allList


	# print J
	# print P
	# print S
	# print K

	

	print "Case #%d: %d" %(t+1, total)
	for i in allList:
		print " ".join(i)



