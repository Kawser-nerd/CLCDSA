import random
import math
import sys
n = 1000
c = [0] * n
'''
f = [[0.0] * n for i in range(n)]
for i in range(n):
	f[i][i] = 1.0
for i in range(n):
	print i
	for j in range(n):
		if j != i:
			for k in range(n):
				f[j][k] = (f[j][k] * (n - 1) + f[i][k]) / n
	for k in range(n):
		f[i][k] = 1.0 / n

print >>open("3.txt", "w"), f
'''
f = eval(open("3.txt", "r").read())

cnt = 0
t = input()
for tt in xrange(t):
	n = input()
	z = 0
	a = map(int, raw_input().split())
	for j in range(n):
		z += math.log(f[j][a[j]])
#	print z
	print "Case #%d:"%(tt + 1),
	if z < -6907:
		print "GOOD"
	else:
		print "BAD"
