def numberneeded(lst):
	invites = 0
	standing = 0
	for i in range(len(lst)):
		if lst[i] != 0 and standing < i:
			invites += (i - standing)
			standing += (i - standing)
		standing += lst[i]
	return(invites)

import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		inputstring = inputLines.pop(0).rstrip().split(' ')[1]
		inputlist = [int(x) for x in list(inputstring)]
		fileOUT.write('Case #' + str(num+1) + ': ' + str(numberneeded(inputlist)) + '\n')
