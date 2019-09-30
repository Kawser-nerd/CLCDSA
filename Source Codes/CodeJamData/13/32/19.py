def getPosition(s):
	pos = [0,0]
	for i in range(len(s)):
		if s[i]=="N":pos[1]+=(i+1)
		if s[i]=="W":pos[0]-=(i+1)
		if s[i]=="E":pos[0]+=(i+1)
		if s[i]=="S":pos[1]-=(i+1)
	return pos


#print getPosition("ENWSEN")
#print getPosition("ENSWN")


for T in range(int(raw_input())):
	finalPos = map(int, raw_input().split())
#	print finalPos
	res = ""
	pos = [0,0]
	i = 1
	while pos!=finalPos:
		if pos[0]!=finalPos[0]:
			if pos[0]>finalPos[0]:
				res+="EW"
				pos[0]-=1
			else:
				res+="WE"
				pos[0]+=1
		else:
			if pos[1]>finalPos[1]:
				res+="NS"
				pos[1]-=1
			else:
				res+="SN"
				pos[1]+=1
		i+=2
#	print getPosition(res)
	print "Case #%d: %s"%(T+1,res)

