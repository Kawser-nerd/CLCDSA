
import sys
import math
from collections import defaultdict

f = open('C-large.in')
tests = int(f.readline())


for t in xrange(tests):
	c,d,v = map(int, f.readline().rstrip().split())
	denoms = map(int, f.readline().rstrip().split())
	needed = 0
	if denoms[0] != 1:
		needed += 1
		denoms = [1] + denoms
	curmax = 0
	while True:
		prevdenom = denoms[0]
		curmax += prevdenom*c
		denoms.pop(0)
		if curmax >= v:
			break
		if len(denoms) == 0 or denoms[0] > curmax + 1:
			denoms = [curmax + 1] + denoms
			needed += 1
	print "Case #" + str(t + 1) + ": " + str(needed)
	



#
#sys.stdin.readline().rstrip()

