#!/usr/bin/python
import sys
import math
input = open(sys.argv[1], "r")
output = open("speed.out", "w")
#Algorithm: This seems like a textbook dynamic programming problem, if only I had read more textbooks...
caseN = 0
case = 0
n = 0
m = 0
X = 0
Y = 0
Z = 0
acc = 0
A = [] #limit generator array
B = [] #limit generatED array
C = [] #subsequences for this number
MODNUM = 1000000007
for line in input:
    if caseN == 0:
	caseN = int(line)
	continue
    elif n == 0:
	intLine = map(int, line.split(' '))
	n = intLine[0]
	m = intLine[1]
	X = intLine[2]
	Y = intLine[3]
	Z = intLine[4]
	acc = m-1
    elif acc > 0:
	acc -= 1
	A += [int(line)]
    else:
	A += [int(line)]
	#Start solving
	ans = 0
	B = [0 for x in range(n)]
	C = [0 for x in range(n)]
	#generate numbers
	for i in range(n):
	    B[i] = int(A[i%m])
	    A[i%m] = (X * A[i%m] + Y*(i+1))%Z
	#Traverse array... backwards
	loopNums = range(n)
	loopNums.reverse()
	for i in loopNums:
	    seqNum = 1
	    for j in range(i+1,n):
		if B[j] > B[i]:
		    seqNum += C[j]
		    seqNum %= MODNUM
	    C[i] = seqNum
	    C[i] %= MODNUM
	    ans += seqNum
	    ans %= MODNUM
	#output and clean up
	case += 1
	output.write("Case #"+str(case)+": "+str(ans)+"\n")
	n = 0
	A = []

input.close()
output.close()
