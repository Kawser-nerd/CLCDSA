#!/usr/bin/python
fin = open("b.in","r")
n = int(fin.readline())
fout = open("b.out", "w")
for i in xrange(1, n+1):
	p, k, l = map(int, fin.readline().split())
	freqs = map(int, fin.readline().split())
	
	if p * k < l:
		print >> fout, "Case #%d: Impossible" % i
	else:
		freqs.sort(lambda a, b: b - a)
		total = 0
		for j in xrange(1, p+1):
			total += sum(freqs[:k]) * j
			freqs = freqs[k:]
			if len(freqs) == 0:
				break
		print >> fout, "Case #%d: %d" % (i, total)
		
		
fout.close()