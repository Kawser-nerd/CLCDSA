import math

def numberofsteps(lst,bites):
	output = bites
	for item in lst:
		output += (int(math.ceil(item/bites)) - 1)
	return output

def process(lst):
	m = max(lst)
	return min([numberofsteps(lst,x) for x in range(1,m+1)])

import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		numberofplates = int(inputLines.pop(0))
		inputlist = [int(x) for x in inputLines.pop(0).rstrip().split(' ')]
		fileOUT.write('Case #' + str(num+1) + ': ' + str(process(inputlist)) + '\n')