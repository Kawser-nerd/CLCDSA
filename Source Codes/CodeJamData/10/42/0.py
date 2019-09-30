from math import *
inf = open("file.in")
ouf = open("file.out","w")
counttests = int(inf.readline().split()[0])
case = 0
def answer(x):
	global case, counttests
	if case > counttests:
		exit
	case += 1
	print >>ouf, "Case #"+str(case)+": "+str(x)
	print "Case #"+str(case)+": "+str(x)

dyn = n = nn = m = p = 0
def rec(c, v):
	global dyn, n, nn, m, p
	if v>=nn-1:
		if c>=m[v-nn+1]:
			return 0
		else:
			return 1000000000
	if dyn[c][v]==-1:
		dyn[c][v] = min(p[v]+rec(c+1,v*2+1)+rec(c+1,v*2+2),rec(c,v*2+1)+rec(c,v*2+2))
	return dyn[c][v]


for iii in xrange(counttests):
	n = int(inf.readline().split()[0])
	nn = 2**n
	m = map(int, inf.readline().split())
	for i in xrange(len(m)):
		m[i] = n-m[i]
	p = [0]*nn
	dyn = []
	for i in xrange(n):
		dyn.append([-1]*nn)
	for i in xrange(n):
		tmp = map(int, inf.readline().split())
		for j in xrange(len(tmp)):
			p[2**(n-i-1)-1+j] = tmp[j]
	answer(rec(0,0))

