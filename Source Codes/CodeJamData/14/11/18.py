import sys

f = open(sys.argv[1])
for t in range(1, int(f.readline())+1):
	N, L = map(int, f.readline().split())
	flows = map(lambda x: int(x, 2), f.readline().split())
	devices = sorted(map(lambda x: int(x, 2), f.readline().split()))
	
	mins = L+1;
	f1 = flows[0]
	
	scombs = []
	for d in devices:
		scombs.append(f1 ^ d)
		
	for scomb in scombs:
		devs = sorted([x^scomb for x in flows])
		if devs == devices:
			num_ones = bin(scomb)[2:].count('1')
			if num_ones < mins:
				mins = num_ones
		
	if mins < L+1:
		print 'Case #%d: %d' % (t, mins)
	else:
		print 'Case #%d: %s' % (t, "NOT POSSIBLE")
