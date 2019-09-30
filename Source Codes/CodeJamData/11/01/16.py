def abs(m):
	if m>=0: return m
	else: return -m

case=int(raw_input())
for repeat in xrange(case):
	line=raw_input().split()
	bTask=[]
	oTask=[]
	taskOrder=[]
	for i in range(1,len(line),2):
		if line[i]=="O": oTask+=[int(line[i+1])]
		if line[i]=="B": bTask+=[int(line[i+1])]
		taskOrder+=[line[i]]
	#print bTask
	#print oTask
	#print taskOrder
	t=0
	bCurrent=0
	oCurrent=0
	bPos=1
	oPos=1
	taskCurrent=0
	while taskCurrent<len(taskOrder):
		if taskOrder[taskCurrent]=="B":
			if bPos<bTask[bCurrent]: bPos+=1
			else:
				if bPos>bTask[bCurrent]: bPos-=1
				else:
					bCurrent+=1
					taskCurrent+=1
			if oCurrent<len(oTask):
				if oPos<oTask[oCurrent]: oPos+=1
				else:
					if oPos>oTask[oCurrent]: oPos-=1
		else:
			if bCurrent<len(bTask):
				if bPos<bTask[bCurrent]: bPos+=1
				else:
					if bPos>bTask[bCurrent]: bPos-=1
			if oPos<oTask[oCurrent]: oPos+=1
			else:
				if oPos>oTask[oCurrent]: oPos-=1
				else:
					oCurrent+=1
					taskCurrent+=1
		t+=1
	print "Case #%d: %d" %(repeat+1,t)
	