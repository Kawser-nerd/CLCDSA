#!/usr/bin/python
fin = open("c.in","r")
n = int(fin.readline())
fout = open("c.out", "w")

def ugly(n):
	if n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0:
		return 1
	return 0

def count(n, k, s, pos):
	if len(n) == 0:
		return ugly(k+s)
	
	a = 0
	if pos:
		a += count(n[1:], k, s * 10 + int(n[0]), True)
	else:
		a += count(n[1:], k, s * 10 - int(n[0]), False)
	a += count(n[1:], k + s, int(n[0]), True)
	a += count(n[1:], k + s, -int(n[0]), False)
	return a

for i in xrange(1, n+1):
	d = fin.readline().strip()
	c = count(d[1:], 0, int(d[0]), True)
	print c
	print >> fout, "Case #%d: %d" % (i, c)