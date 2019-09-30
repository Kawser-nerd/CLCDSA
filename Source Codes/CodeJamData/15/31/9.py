
import sys
import math

f = open('A-large.in')
#f = open('test')
lines = int(f.readline())

idx = 1
for line in f:
	r,c,w = map(int, line.split())
	perRow = c//w
	if c%w != 0:
		print "Case #" + str(idx) + ": " + str(perRow*r + w)
	else:
		print "Case #" + str(idx) + ": " + str(perRow*r + w-1)
	idx += 1
	




#
#sys.stdin.readline().rstrip()

