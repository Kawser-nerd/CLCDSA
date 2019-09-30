T = int(raw_input())

for kei in xrange(T):
	N = int(raw_input())
	height = {}
	succ = 0
	q = []
	for i in xrange(N):
		d,n,w,e,s,dd,dp,ds = (int(x) for x in raw_input().split())
		for a in xrange(n):
			nd = d+dd*a
			nw = w+dp*a
			ne = e+dp*a
			ns = s+ds*a
			q.append((nd,nw,ne,ns,'tribe'+str(i+1)))
	q.sort()
	#print('q = '+str(q))
	temp = []
	group = []
	for i in q:
		# print(temp[0] if len(temp) > 0 else "NONE")
		if len(temp) == 0 or temp[0][0] == i[0]:
			temp.append(i)
		else:
			group.append(temp)
			temp = [i]
	if temp:
		group.append(temp)
	#print('Group:')
	for i in group:
		#print(i)
		#print('Group: '+str(i))
		for (d,w,e,s,tribe) in i:
			for j in xrange(w,e):
				if j not in height:
					height[j] = 0
				if height[j] < s:
					#print('Success:' +str((d,w,e,s)))
					succ += 1
					break
		for (d,w,e,s,tribe) in i:
			for j in xrange(w,e):
				if j not in height:
					height[j] = 0
				height[j] = max(height[j],s)
	print('Case #%d: %d' % (kei+1, succ))
