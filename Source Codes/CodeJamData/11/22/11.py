

#fp = open('B-small-attempt2.in', 'r')
fp = open('B-large.in', 'r')
#fp = open('input', 'r')
n = int(fp.next())

def max_sum_subsequence(seq):
	maxsofar = 0
	maxendinghere = 0
	for s in seq:
		# invariant: maxendinghere and maxsofar are accurate
		# are accurate up to s
		maxendinghere = max(maxendinghere + s, 0)
		maxsofar = max(maxsofar, maxendinghere)
	return maxsofar
   
case = 1

for line in fp:
	result = 0
	npoints, dist = [int(x) for x in line.strip().split()]
	
	#print npoints, dist
	
	points = []
	nvend = 0
	
	for x in range(npoints):
		line = [int(x) for x in fp.next().strip().split()]
		
		nvend += line[1]
		
		for y in range(line[1]):
			points.append(line[0])
		
		#print '>', line
	
	totaldist = dist * (nvend - 1)
	points.sort()
	
	dists = []
	for x in range(len(points) - 1):
		dists.append(dist - (points[x+1] - points[x]))
	
	result = max_sum_subsequence(dists) / 2.
		
	print 'Case #%d: %.6f' % (case, result)
	
	case += 1

	#break
	
