#!/usr/bin/python
# Google Code Jam 2008
# Problem 3-D
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
cache = {}
r = {}

def solveR(x, y, H, W):
	if x == W and y == H: return 1
	if globals()["cache"].has_key((x,y)): return globals()["cache"][(x,y)]
	total = 0
	if x + 2 <= W and y + 1 <= H and (not r.has_key((x+2,y+1))): total += solveR(x+2,y+1,H,W)
	if x + 1 <= W and y + 2 <= H and (not r.has_key((x+1,y+2))): total += solveR(x+1,y+2,H,W)
	total = total % 10007
	globals()["cache"][(x,y)] = total
	return total

def solve(caseNum):
	H, W , R = map(int, sys.stdin.readline().strip().split(" "))
	globals()["r"] = {}
	for i in range(R):
		tmp= map(int, sys.stdin.readline().strip().split(" "))
		globals()["r"][(tmp[1], tmp[0])] = 1
	
	globals()["cache"] = {}
	
	total = solveR(1,1, H , W)
	

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
