T=int(raw_input())
for repeat in range(T):
	raw_input()
	dataStr=raw_input().split()
	dataInt=[]
	for i in range(len(dataStr)):
		dataInt+=[int(dataStr[i])]
	pSum=0
	for i in range(len(dataInt)):
		pSum^=dataInt[i]
	if pSum!=0: print "Case #%d: NO" %(repeat+1)
	else:
		min=0
		actSum=0
		for i in range(len(dataInt)):
			actSum+=dataInt[i]
			if dataInt[i]<dataInt[min]: min=i
		actSum-=dataInt[min]
		print "Case #%d: %d" %(repeat+1,actSum)