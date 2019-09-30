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
	print >>ouf, 'Case #%d: %d' % (printcounter,a)
	#print >>ouf, 'Case #%d: %.5f %.5f' % (printcounter,a)
	#print >> ouf, st
	#print st

def solvetest():
	inp = inf.readline().split()
	inp = map(int, inp)	
	[l,t,n,c] = inp[:4]
	a = inp[4:]
	sum =0
	for i in a:
		sum +=i
	i = 0
	b = a[:]
	b.sort()
	b.reverse()
	alltime= (n/c) *sum *2
	for i in xrange(n %c):
		alltime += a[i]*2
	if (t >=alltime) or l ==0:
		printstr(alltime)
		return
	ccc = t/(sum*2)#
	ttt = ccc*(sum*2)
	t = t - ttt
	n = n - ccc*c
	i = 0
	arr = []
	while t >= a[i]*2:
		t-=a[i]*2
		ttt+=a[i]*2
		i+=1
	if t!=0:
		arr.append(a[i]-t*0.5)
		i+=1
	ttt+=t
	if n < c:
		while i<n:
			arr.append(a[i])
			i+=1
		vse = 1
	else:
		while i<c:
			arr.append(a[i])
			i+=1
		vse = 0
	ccc = 0
	if not vse:
		n = n-c
		ccc = n/c
		n = n%c
		i = 0
		while i < n:
			arr.append(a[i])
			i+=1
	mgarr = arr + a*ccc
	mgarr.sort()
	mgarr.reverse()
	#print mgarr
	i = 0
	while i < l and i < len(mgarr):
		ttt += mgarr[i]
		i += 1
	while i< len(mgarr):
		ttt += mgarr[i]*2
		i += 1
	printstr(int(round(ttt)))
	
precount()
testnum = int(inf.readline())
for test in xrange(testnum):
	solvetest()
close_files()
