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
	P, K, L = map(int, sys.stdin.readline().strip().split(" "))
	frq = map(int, sys.stdin.readline().strip().split(" "))

	frq2 = []
	for i in range(0, len(frq)):
		frq2.append((frq[i], i))
	
	frq2.sort()
	frq2.reverse()	
	keys = [0] * K

	curk = 0
	total = 0

	for k in frq2:
		if keys[curk] > P:
			sys.stdout.write("Case #%d: Impossible" % caseNum)
			return
		keys[curk] += 1
		total += k[0] * keys[curk]
		curk += 1
		if curk >= len(keys):
			curk = 0


	sys.stdout.write("Case #%d: %s" % (caseNum, total))

# ---------------------------------------------------------------------------------------------------------------

casesCount = int(re.findall(r'[\d]+', sys.stdin.readline())[0])
first = True
for case in range(1, casesCount + 1):
	if(first):
		first = False
	else:
		print ""
	solve(case)
