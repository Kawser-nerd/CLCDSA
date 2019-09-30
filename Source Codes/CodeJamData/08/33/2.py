#!/usr/bin/python
fin = open("d.in","r")
N = int(fin.readline())
fout = open("d.out", "w")

for i in xrange(1, N+1):
	n, m, X, Y, Z = map(long, fin.readline().split())
	A = []
	for j in xrange(m):
		A.append(long(fin.readline()))
	s = []
	for j in xrange(n):
		s.append(A[j % m])
		A[j % m] = (X * A[j % m] + Y * (j + 1)) % Z
	
	count = [1] * n
	for j in xrange(n):
		p = s[j]
		for k in xrange(j):
			if p > s[k]:
				count[j] += count[k]
				
	total = sum(count) % 1000000007
	print total
	print >> fout, "Case #%d: %d" % (i, total)
	
fout.close()