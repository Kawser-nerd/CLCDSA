import sys
import math

f=open('t.txt','r')
g=open('file.txt','w')


for i in range(1,int(f.readline())+1):
	[d,n,a]=[float(j) for j in f.readline().split()]
	n=int(n)
	start=float(f.readline().split()[1])
	if n>1:
		[t1,x1]=[float(j) for j in f.readline().split()]
		#print t1,x1,'-'
		vel=(x1-start)/t1
	#print start,vel
	if start>=d:
		otime=0.0
	else:
		otime=(d-start)/vel
	accels=[float(j) for j in f.readline().split()]
	print 'Case #' + str(i) + ':'
	g.write('Case #' + str(i) + ':' + '\n')
	for j in accels:
		mtime=math.sqrt(2*d/j)
		print str(max(mtime,otime))
		g.write(str(max(mtime,otime))+'\n')
g.close()