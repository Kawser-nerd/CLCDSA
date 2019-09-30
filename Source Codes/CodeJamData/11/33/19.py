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
	inp = inf.readline().split()
	[n,l,h] = map(int, inp)	
	inp = inf.readline().split()
	a = map(int, inp)
	f = 0
	for i in xrange(l,h+1):
		bad = 0
		for j in xrange(n):
			if (i % a[j] ==0)or (a[j]% i==0):
				pass
			else:
				bad = 1
		if not bad:
			f = i
			break
	if f:
		printstr(str(f))
	else:
		printstr('NO')
precount()
testnum = int(inf.readline())
for test in xrange(testnum):
	solvetest()
close_files()
