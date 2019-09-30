import sys
import os
import time

import psyco
#psyco.full()



def possible(power):
	global ships
	for q1 in range(-1,2,2):
		for q2 in range(-1,2,2):
			res = []
			for q3 in range(-1,2,2):
				sx = q1*q3
				sy = q2*q3
				sz = q3
				bound = 1000000
				for x,y,z,p in ships:
					bound = min(bound,x*sx+y*sy+z*sz + power*p)
				res.append(bound)
			if res[0]+res[1]<0:
				return False
	return True

def solve():
	global ships
	n = int(getLine())

	ships = []

	for i in range(n):
		x,y,z,p = map(int,getLine().split(" "))
		ships.append((x,y,z,p))

	p1 = 0
	p2 = 2e6

	while p2-p1>1e-7:
		power = 0.5*(p1+p2)
#		print power
		if possible(power):
			p2 = power
		else:
			p1 = power

	return "%.7f"%(0.5*(p1+p2))



#########
def getLine():
	global fin
	line = fin.readline()
	if line[-1]=="\n":
		line = line[:-1]
	return line

#########
if len(sys.argv) != 2:
	print "Specify input file"
	exit(1)

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+".out","wt")

n = int(getLine())

start = time.clock()
for i in range(1,n+1):
	print "Solving",i
	fout.write("Case #%s: "%i)
	fout.write(solve())
	fout.write("\n")
print "It takes %.2fs"%(time.clock()-start)

fout.close()
