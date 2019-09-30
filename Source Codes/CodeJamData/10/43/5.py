from pprint import pprint

C = int(raw_input().strip())

x1,y1,x2,y2 = 0,1,2,3

def touching(r1,r2):
	if (r1[x1] <= r2[x2]+1) and (r2[x1] <= r1[x2]+1) and (r1[y1] <= r2[y2]+1) and (r2[y1] <= r1[y2]+1):
		if r1[x1]>r2[x2] and r1[y1]>r2[y2]: return False
		if r2[x1]>r1[x2] and r2[y1]>r1[y2]: return False
		return True
	return False

def count_group(g):
	max_x = max(map(lambda q:q[2],g))
	max_y = max(map(lambda q:q[3],g))
	return  max(map(lambda q: (max_x-q[0])+(max_y-q[1])+1 , g))

for case in range(1,C+1):
	lonerects = [];
	R = int(raw_input().strip())
	for r in xrange(R):
		lonerects.append(tuple(map(int,raw_input().strip().split(' '))))
	rectgroups = []
	for lr in lonerects:
		matches = []
		for rgi in xrange(len(rectgroups)):
			rg = rectgroups[rgi]
			# find all matches
			for r in rg:
				if touching(r,lr):
					matches.append(rgi)
					break
		if len(matches) == 0:
			rectgroups.append([lr])
		elif len(matches) == 1:
			rectgroups[matches[0]].append(lr)
		else:
			newgroup = [lr]
			matches.sort()
			matches.reverse()
			for m in matches:
				newgroup.extend(rectgroups[m])
				rectgroups.pop(m)
			rectgroups.append(newgroup)

	
		#pprint(rectgroups)

	ans = max(map(count_group,rectgroups))
	print "Case #%d: %d" % (case,ans)
