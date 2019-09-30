import sys
import os
import time

import psyco
#psyco.full()

def solve():
	imp = 100000

	m,v = map(int,getLine().split(" "))
	G = []
	C = []
	leafs = []
	for i in range((m-1)/2):
		g,c = map(int,getLine().split(" "))
		G.append(g)
		C.append(c)
	for i in range((m+1)/2):
		leafs.append(int(getLine()))


	nodes = [0]*((m-1)/2) + leafs
	for i in range((m-1)/2-1,-1,-1):
		if G[i] == 0:
			nodes[i] = nodes[2*i+1] or nodes[2*i+2]
		else:
			nodes[i] = nodes[2*i+1] and nodes[2*i+2]


	cost = [[None,None] for i in range((m-1)/2)]
	for i in leafs:
		if i == 0:
			cost.append([0,imp])
		else:
			cost.append([imp,0])


	for i in range((m-1)/2-1,-1,-1):
		cost[i][0] = imp
		cost[i][1] = imp
		for j in range(2):
			for k in range(2):
				if C[i]==1 or G[i]==1:
					cost[i][j and k] = min(cost[i][j and k],
						cost[2*i+1][j]+cost[2*i+2][k]+1-G[i])
				if C[i]==1 or G[i]==0:
					cost[i][j or k] = min(cost[i][j or k],
						cost[2*i+1][j]+cost[2*i+2][k]+G[i])

#	print cost

	if cost[0][v]>=imp:
		return "IMPOSSIBLE"
	else:
		return str(cost[0][v])



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
