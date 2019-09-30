import os, sys, math

inFile = None
outFile = None

def printAnswer(case, answer):
	outFile.write('Case #{0}: {1}\n'.format(case+1, answer))



def solveSimple(tc, a, d):
	t = math.sqrt(2.0*d/a)

	if t < tc:
		t = tc

	outFile.write('{0}\n'.format(t))

def solveCase(caseNo):
	(d, n, a) = inFile.readline().strip().split()
	d = float(d)
	n = int(n)
	a = int(a)

	printAnswer(caseNo, '')

	xc = d + 100.0
	tc = 0
	if n==1:
		(t0, x0) = map(float, inFile.readline().strip().split())
		if x0 > d + (0.00000001):
			tc = 0
		else:
			tc = t0
			print tc



	if n==2:
		(t0, x0) = map(float, inFile.readline().strip().split())
		(t1, x1) = map(float, inFile.readline().strip().split())

		
		vc = (x1-x0)/(t1-t0)
		if x1 > d:
			tc = t0 + (d-x0)/vc
		else:
			tc = t1


	av = map(float, inFile.readline().strip().split())

	for a in av:
		solveSimple(tc, a, d)

def main():
	cases = int(inFile.readline().strip())
	for case in range(cases):
		solveCase(case)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()