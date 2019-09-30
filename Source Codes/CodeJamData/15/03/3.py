quaterniontable = ['uijknabc','inkbaucj','jcnibkua','kjancbiu','nabcuijk','aucjinkb','bkuajcni','cbiukjan']

def quaternionencrypt(char):
	for i in range(8):
		if 'uijknabc'[i] == char:
			return i

def quaterniondecrypt(num):
	return 'uijknabc'[num]

def quaternionmult(char1,char2):
	return quaterniontable[quaternionencrypt(char1)][quaternionencrypt(char2)]

def quaternionstringproduct(inputstring):
	prod = 'u'
	for char in inputstring:
		prod = quaternionmult(prod,char)
	return prod

def quaternionstringpower(inputstring,n):
	prod = quaternionstringproduct(inputstring)
	power = n % 4
	output = 'u'
	for i in range(power):
		output = quaternionmult(output,prod)
	return output
	
def stringtester(inputstring,power):
	fullproduct = quaternionstringpower(inputstring,power)
	if fullproduct != 'n':
		return 'NO'
	teststring = inputstring * min(power,8)
	prod = 'u'
	while teststring != '':
		prod = quaternionmult(prod,teststring[0])
		teststring = teststring[1:]
		if prod == 'i':			
			while teststring != '':
				prod = quaternionmult(prod,teststring[0])
				teststring = teststring[1:]
				if prod == 'k':
					return 'YES'
	return 'NO'

import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		power = int(inputLines.pop(0).rstrip().split(' ')[1])
		inputstring = str(inputLines.pop(0).rstrip())
		fileOUT.write('Case #' + str(num+1) + ': ' + stringtester(inputstring,power) + '\n')