#!/usr/bin/python

IM = 10000000

fin = open("a.in", "r")
fout = open("a.out", "w")

n = int(fin.readline())
for i in xrange(1, n+1):
	m, v = map(int, fin.readline().split())
	tree = []
	for j in xrange(m):
		tree.append(map(int, fin.readline().split()))
	
	changes = [(None, None)] * ((m-1)/2)
	for val in tree[(m-1)/2:]:
		if val[0]:
			changes.append((IM, 0))
		else:
			changes.append((0, IM))
			
	for j in xrange((m-1)/2-1, -1, -1):
		c = tree[j][1]
		o = tree[j][0]
		no = (o+1)%2
		
		zero = [0, 0]
		one = [0, 0]
		zero[1] = min(changes[j*2+1][0] + min(changes[j*2+2]), changes[j*2+2][0] + min(changes[j*2+1]))
		one[1] = changes[j*2+1][1] + changes[j*2+2][1]
		
		zero[0] = changes[j*2+1][0] + changes[j*2+2][0]
		one[0] = min(changes[j*2+1][1] + min(changes[j*2+2]), changes[j*2+2][1] + min(changes[j*2+1]))
		
		
		if c:
			changes[j] = (min(zero[o], zero[no]+1), min(one[o], one[no]+1))
		else:
			changes[j] = (zero[o], one[o])
		
	#print changes
	output = changes[0][v]
	if output >= IM:
		output = "IMPOSSIBLE"
	print "Case #%d: %s" % (i, str(output))
	print >> fout, "Case #%d: %s" % (i, str(output))
	
fout.close()
