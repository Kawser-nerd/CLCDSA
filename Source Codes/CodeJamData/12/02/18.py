def ramp(p):
	if p>=0: return p
	else: return 0

T=int(raw_input())
for repeat in xrange(T):
	line_arr=raw_input().split()
	N,S,p=int(line_arr[0]),int(line_arr[1]),int(line_arr[2])
	t=[]
	for i in xrange(3,len(line_arr)):
		t.append(int(line_arr[i]))
	count_n=0
	count_s=0
	for j in t:
		if j>=p+2*ramp(p-1): count_n+=1
		elif j>=p+2*ramp(p-2): count_s+=1
	count=count_n
	if count_s<=S: count+=count_s
	else: count+=S
	print "Case #%d: %d"%(repeat+1,count)
