import sys

t = int (sys.stdin.readline().split()[0])

for i in range (t):
	n, p = map (int, sys.stdin.readline().split())

	indep = 1
	pt = p
	x = n - 1
	while x >= 0:
		if pt > 2**x: 
			indep += 1
			pt -= 2 ** x
		else: break
		x -= 1
	indep = 2**indep - 2

	if p == 2**n: indep = 2**n - 1

	dep = 0
	x = n
	while x > 0:
		if p >= 2**x: 
			break
		dep += 1
		x -= 1
	dep = 2**n - 2**dep

	if p == 1: dep = 0

	print "Case #%d: %d %d" % (i + 1, indep, dep)
