#!/usr/bin/python
import sys
import math
input = open(sys.argv[1], "r")
output = open("codejam.out", "w")
caseN = 0
case = 0
P = 0
K = 0
L = 0
#Greedy solution works for once...

for line in input:
    if caseN == 0:
	caseN = int(line)
	continue
    if P == 0:
	intLine = map(int, line.split(' '))
	P = intLine[0]
	K = intLine[1]
	L = intLine[2]
    else:
	ans = 0
	acc = 0
	curCost = 1
	freqs = map(int, line.split(' '))
	freqs.sort()
	freqs.reverse();
	for freq in freqs:
	    ans += curCost*freq
	    acc += 1
	    if acc == K:
		acc = 0
		curCost += 1
	case += 1
	output.write("Case #"+str(case)+": "+str(ans)+"\n")
	P = 0

input.close()
output.close()
