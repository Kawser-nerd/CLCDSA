from math import *
inf = open("file.in")
ouf = open("file.out","w")
counttests = int(inf.readline().split()[0])
case = 0
def answer(x):
	global case, counttests
	if case > counttests:
		exit
	case += 1
	print >>ouf, "Case #"+str(case)+": "+str(x)
	print "Case #"+str(case)+": "+str(x)

for ii in xrange(counttests):
	n = int(inf.readline().split()[0])-1
	a = [];
	for i in xrange(2*n+1):
		a.append(inf.readline())
		a[i] = a[i][:-1]
		while len(a[i])<2*n+1:
			a[i] += ' '
	tekh = 0
	tekv = 0
	for i in xrange(0,2*n+1):
		resh = 1
		resv = 1
		for k in xrange(2*n+1):
			for j in xrange(2*n+1):
				if i-j<0 or i+j>=2*n+1:
					continue
				if a[i-j][k]!=a[i+j][k] and a[i-j][k]!=' ' and a[i+j][k]!=' ':
					resh=0
				if a[k][i-j]!=a[k][i+j] and a[k][i-j]!=' ' and a[k][i+j]!=' ':
					resv=0
		if resh==1 and abs(tekh-n)>abs(i-n):
			tekh=i
		if resv==1 and abs(tekv-n)>abs(i-n):
			tekv=i
	answer((abs(tekh-n)+abs(tekv-n)+n+1)**2-(n+1)**2)
