import math
inf = open("in.txt", "r")
ouf = open('out.txt','w')

def close_files():
	inf.close
	ouf.close

def precount():
	pass

printcounter = 0
def printstr(a):
	global printcounter
	printcounter +=1
	print >>ouf, 'Case #%d: %s' % (printcounter,a)
	#print >>ouf, 'Case #%d: %.5f %.5f' % (printcounter,a)
	#print >> ouf, st
	#print st

def solvetest():
	global printcounter
	[r, c] = inf.readline().split()
	r, c = int(r), int(c)
	a = []
	for i in xrange(r):
		a.append(list(inf.readline().strip()))
	bad = 0
	for i in xrange(r):
		for j in xrange(c):
			if a[i][j]=='#':
				if i == r-1 or j == c-1:
					bad = 1
					break
				if a[i+1][j]!= '#' or a[i][j+1]!='#'or a[i+1][j+1]!='#':
					bad = 1
					break
				a[i][j]='/'
				a[i+1][j]='\\'
				a[i][j+1]='\\'
				a[i+1][j+1]='/'
		if bad:
			break
	printcounter +=1
	print >>ouf, 'Case #%d:' % (printcounter)
	if bad:
		print >>ouf, 'Impossible'
	else:
		for i in xrange(r):
			s = ''
			for j in xrange(c):
				s = s+ a[i][j]
			print >>ouf, s
			
	
	
	
precount()
testnum = int(inf.readline())
for test in xrange(testnum):
	solvetest()
close_files()
