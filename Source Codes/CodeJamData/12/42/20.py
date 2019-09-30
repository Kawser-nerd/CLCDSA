"""
# gen input
import random
R = []
for i in range(1000):
	R += [random.random()*100000]
S = 5*3.14159265358979*sum(r**2 for r in R)
print 1000,S**0.5,S**0.5
print " ".join(str(r) for r in R)
exit(0)
"""

for test in range(input()):
	N,W,L=map(float,raw_input().split())
	R=map(float,raw_input().split())
	R = [r*1.00001 for r in R]
	P = []
	c = 0
	for r in R:
		c += 1
		#print c
		Y = [0.0]+[p[1]+p[2]+r+0.00001 for p in P]
		Y.sort()
		cx,cy=None,None
		# x,y
		TP = [(p[0]+p[2]+r,p[1],p[2]) for p in P]
		TP.sort()
		TP = TP[::-1]
		for y in Y:
			x = 0.0
			#for p in P:
			#	if p[2]+r>abs(y-p[1]):
			#		x = max(x,p[0]+r+p[2])
			for p in TP:
				if p[2]+r>abs(y-p[1]):
					x = p[0]
					break
			if x<W:
				cx,cy=x,y
				break
		if cx is None or cy>=L:
			print "ERROR!"
			break
		P += [(cx,cy,r)]
	for p in P:
		if not (0<=p[0]<W and 0<=p[1]<L):
			print "!"
		for q in P:
			if p!=q:
				if (p[0]-q[0])**2+(p[1]-q[1])**2 <= (p[2]/1.00001+q[2]/1.0001)**2:
					print p,q
					print "!"
	print "Case #%s:"%(test+1),
	for p in P:
		print "%.9f"%p[0],"%.9f"%p[1],
	print
