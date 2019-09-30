import sys

def listFind(list,item):
	for i in range(len(list)):
		if list[i]==item: return i
	return -1

T=int(raw_input())
for repeat in range(T):
	line=raw_input().split()
	C=int(line[0])
	cList=line[1:1+C]
	D=int(line[1+C])
	dList=line[2+C:2+C+D]
	N=int(line[2+C+D])
	nList=line[3+C+D]
	#print cList
	#print dList
	#print nList
	res=[]
	for i in range(N):
		res+=[nList[i]]
		#print i
		#print res
		flag=False
		for j in range(C):
			if len(res)>1:
				if cList[j][0]==res[len(res)-1] and cList[j][1]==res[len(res)-2] or cList[j][0]==res[len(res)-2] and cList[j][1]==res[len(res)-1]:
					del res[len(res)-2:len(res)]
					#print res
					res+=[cList[j][2]]
					#print res
					flag=True
		if flag: continue
		for j in range(D):
			if listFind(res,dList[j][0])>-1 and listFind(res,dList[j][1])>-1:
				del res[:]
				#print res
	sys.stdout.write("Case #%d: " %(repeat+1))
	sys.stdout.write("[")
	for i in range(len(res)):
		sys.stdout.write("%s" %(res[i]))
		if i<len(res)-1: sys.stdout.write(", ")
	sys.stdout.write("]\n")