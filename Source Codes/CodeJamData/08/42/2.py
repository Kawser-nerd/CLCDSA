#!/usr/bin/python

IM = 10000000

fin = open("b.in", "r")
fout = open("b.out", "w")


c = int(fin.readline())
for i in xrange(1, c+1):
	n, m, a = map(int, fin.readline().split())
	# n => x
	if n < m:
		x1 = n
		x2 = 1
		y2 = (a+n-1) / n
		y1 = y2*x1 - a
	else:
		y1 = m
		x2 = (a+m-1) / m
		y2 = 1
		x1 = x2*y1 - a
			
	
	output = "0 0 %d %d %d %d" % (x1, y1, x2, y2)
	if y2 > m or x2 > n:
		output = "IMPOSSIBLE"
	print "Case #%d: %s" % (i, str(output))
	print >> fout, "Case #%d: %s" % (i, str(output))
	