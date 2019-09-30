T=int(raw_input())
for repeat in range(T):
	raw_input()
	line=raw_input().split()
	data=[]
	newd=[]
	for i in range(len(line)):
		data+=[int(line[i])]
		newd+=[int(line[i])]
	newd.sort()
	count=0
	for i in range(len(data)):
		if data[i]!=newd[i]: count+=1
	print "Case #%d: %.6f" %(repeat+1,count)