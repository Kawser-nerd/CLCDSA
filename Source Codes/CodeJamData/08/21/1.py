import sys
from copy import deepcopy

import psyco
psyco.full()

def getLine():
	global fin
	line = fin.readline()
	if line[-1]=="\n":
		line = line[:-1]
	return line


def solve():
	n,A,B,C,D,x0,y0,M = map(int,getLine().split(" "))
	coords = []
	for i in range(n):
		coords.append((x0,y0))
		x0 = (A*x0+B)%M
		y0 = (C*y0+D)%M
	
#	print coords
#	count = 0
#	for i in range(len(coords)):
#		for j in range(i+1,len(coords)):
#			for k in range(j+1,len(coords)):
#				if (coords[i][0]+coords[j][0]+coords[k][0])%3 == 0 and\
#				   (coords[i][1]+coords[j][1]+coords[k][1])%3 == 0:
#					count += 1
#					print i,j,k
	
	modCnt = [[[0 for i in range(3)] for j in range(3)]]
	for i in range(n-1,-1,-1):
		res = deepcopy(modCnt[n-i-1])
		res[coords[i][0]%3][coords[i][1]%3] += 1
#		print res
		modCnt.append(res)
	modCnt.reverse()
#	print modCnt

	modCnt1 = [[[0 for i in range(3)] for j in range(3)]]
	for i in range(n-1,-1,-1):
		res = deepcopy(modCnt1[n-i-1])
		for q1 in range(3):
			for q2 in range(3):
				res[(coords[i][0]+q1)%3][(coords[i][1]+q2)%3] += \
					modCnt[i+1][q1][q2]
#		print res
		modCnt1.append(res)
	modCnt1.reverse()
#	print modCnt1

	modCnt2 = [[[0 for i in range(3)] for j in range(3)]]
	for i in range(n-1,-1,-1):
		res = deepcopy(modCnt2[n-i-1])
		for q1 in range(3):
			for q2 in range(3):
				res[(coords[i][0]+q1)%3][(coords[i][1]+q2)%3] += \
					modCnt1[i+1][q1][q2]
#		print res
		modCnt2.append(res)
	modCnt2.reverse()
#	print modCnt2


	return str(modCnt2[0][0][0])

#########
if len(sys.argv) != 2:
	print "Specify input file"
	exit(1)

fin = open(sys.argv[1])


n = int(getLine())

fout = open("out","wt")

for i in range(1,n+1):
	print "Solving",i
	fout.write("Case #%s: "%i)
	fout.write(solve())
	fout.write("\n")

fout.close()