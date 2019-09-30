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
	print "Case #"+str(case)+": "+str(x)
	print >>ouf, "Case #"+str(case)+": "+str(x)

for i in xrange(counttests):
	n = int(inf.readline().split()[0])
	a = []
	for i in xrange(100):
		a.append([0]*100)
	oc=0
	for i in xrange(n):
		t = map(int,inf.readline().split())
		t[0] -= 1
		t[1] -= 1
		t[2] -= 1
		t[3] -= 1
		for x in xrange(t[0],t[2]+1):
			for y in xrange(t[1],t[3]+1):
				if a[x][y]==0:
					oc += 1
				a[x][y]=1
	ans=0
	while oc>0:
		ans+=1
		oc=0
		na = []
		for i in xrange(100):
			na.append([0]*100)
		for x in xrange(1,100):
			for y in xrange(1,100):
				if a[x][y]==0:
					na[x][y] = a[x][y-1] * a[x-1][y]
				else:
					na[x][y] = a[x][y-1] or a[x-1][y]
			if a[x][0]==a[x-1][0]==1:
				na[x][0]=1
			if a[0][x]==a[0][x-1]==1:
				na[0][x]=1
		for x in xrange(100):
			for y in xrange(100):
				oc += na[x][y]
		a=na
	answer(ans)

