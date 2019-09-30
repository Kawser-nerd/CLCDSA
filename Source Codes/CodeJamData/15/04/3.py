'''
Analyzed case by case.
First eliminate boards that aren't divisible by x.
x = 3: If width < 2, Richard uses L-shaped piece
x = 4: If width < 3, Richard uses T-shaped piece
x = 5: If width < 3 or board is 3x5, Richard uses W-shaped piece
x = 6: If width < 4, Richard uses Y-shaped piece 
x > 6: Richard uses piece with a hole in it
'''

def solver(x,r,c):
	if x > 6:
		return 'RICHARD'
	if (r*c) % x != 0:
		return 'RICHARD'
	if x <= 2:
		return 'GABRIEL'
	if x == 3:
		if min(r,c) > 1:
			return 'GABRIEL'
		else:
			return 'RICHARD'
	if x == 4:
		if min(r,c) > 2:
			return 'GABRIEL'
		else:
			return 'RICHARD'
	if x == 5:
		if min(r,c) > 2 and r+c > 8:
			return 'GABRIEL'
		else:
			return 'RICHARD'
	if x == 6:
		if min(r,c) > 3:
			return 'GABRIEL'
		else:
			return 'RICHARD'
		
import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		inputlist = inputLines.pop(0).rstrip().split(' ')
		x = int(inputlist[0])
		r = int(inputlist[1])
		c = int(inputlist[2])
		fileOUT.write('Case #' + str(num+1) + ': ' + solver(x,r,c) + '\n')