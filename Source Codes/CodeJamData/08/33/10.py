#!/usr/bin/python
# Google Code Jam 2008
# Problem 1B-A
# zzmike

import sys
import re
from Numeric import *
#from decimal import *

# ---------------------------------------------------------------------------------------------------------------

sys.setcheckinterval(10000)
PI = arccos(-1)
PI_2 = arccos(-1) / 2

#getcontext().prec = 200
#getcontext().rounding = ROUND_DOWN

# ---------------------------------------------------------------------------------------------------------------




def solve(caseNum):
	n, m, X, Y, Z = map(int, sys.stdin.readline().strip().split(" "))
	A = []
	for i in range(0,m):
		A.append(int(sys.stdin.readline().strip()))
	
	signs = []
	for i in range(0,n):
		signs.append(A[i % m])
		A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z

	total = 0
	aux = []
	for i in range(len(signs)-1, -1, -1):
		count = 1
		for t in aux:
			if t[0] > signs[i]:
				count += t[1]
		aux.append((signs[i], count))
		total += count


	sys.stdout.write("Case #%d: %s" % (caseNum, total % 1000000007))

# ---------------------------------------------------------------------------------------------------------------

casesCount = int(re.findall(r'[\d]+', sys.stdin.readline())[0])
first = True
for case in range(1, casesCount + 1):
	if(first):
		first = False
	else:
		print ""
	solve(case)
