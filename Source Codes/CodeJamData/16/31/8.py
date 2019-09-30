from __future__ import print_function
import numpy
import string
T = int(raw_input())
for i in range(1, T + 1):
	print ("Case #%d:" % i, end = '')
	n = int(raw_input())
	p = [int(x) for x in raw_input().split()]
	while True:
		pp = [x for x in range(len(p)) if p[x] != 0]
		if len(pp) == 0:
			break
		elif len(pp) == 2 and p[pp[0]] == p[pp[1]]:
			print (' ', end = '')
			print (string.uppercase[pp[0]], end = '')
			print (string.uppercase[pp[1]], end = '')
			p[pp[0]] -= 1
			p[pp[1]] -= 1
		else:
			q = numpy.argmax(p)
			print (' ', end = '')
			print (string.uppercase[q], end = '')
			p[q] -= 1
			
	print('')