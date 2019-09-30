import sys
import os
import time

import psyco
#psyco.full()

def pathCost(path):
	global cost
	global backCost
	s = 0
	for i in range(1,len(path)):
		s += cost[path[i-1]][path[i]]
	s += backCost[path[-1]][path[0]]
	return s

def rec(i,cur):
	global cost
	global backCost
	global used
	global curSum
	global path
	global k
	global best

#	print "rec",i,cur

	used[cur] = True
	path.append(cur)
	for j in range(k):
		if not used[j]:
			t = curSum
			curSum += cost[cur][j]
			if i+1<k-1:
				rec(i+1,j)
			else:
				#print "cost",curSum+backCost[j][path[0]]
				best = min(best,curSum+backCost[j][path[0]])
#				print "cos'",pathCost(path+[j])
#				print "path",path+[j]
			curSum = t

	used[cur] = False
	path.pop(-1)
	

def solve():
	global cost
	global backCost
	global used
	global curSum
	global path
	global k
	global best

	k = int(getLine())
	s = getLine()
	assert len(s)%k == 0



	cost = []
	backCost = []
	for i in range(k):
		cost.append([])
		backCost.append([])
		for j in range(k):
			c = 0
			bc = 0
			for q in range(0,len(s),k):
				if s[q+i]!=s[q+j]:
					c += 1
			for q in range(k,len(s),k):
				if s[q+i-k]!=s[q+j]:
					bc += 1
			cost[-1].append(c)
			backCost[-1].append(bc)

#	print s
#	print cost
#	print backCost

	curSum = 0
	used = [False]*k
	path = []

	best = 100000
	for i in range(k):
		rec(0,i)
	return str(best+1)



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
