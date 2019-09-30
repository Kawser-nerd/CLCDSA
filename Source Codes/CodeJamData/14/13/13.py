import sys
from random import *

def sh0(a):
	for i in xrange(len(a)):
		p = randint(i, len(a)-1)
		a[i], a[p] = a[p], a[i]
	return a

def sh(a):
	for i in xrange(len(a)):
		p = randint(0, len(a)-1)
		a[i], a[p] = a[p], a[i]
	return a

N = 1000
CNT = [ [0]*N for _ in xrange(N) ]
for i in xrange(600000):
	a = sh(range(N))
	for j in xrange(N):
		CNT[a[j]][j] += 1
	if i%100 == 99:
		print >> sys.stderr, i+1

for i in xrange(N):
	print " ".join([ "%7d"%x for x in CNT[i] ])
