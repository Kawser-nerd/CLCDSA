import sys
import os
import time
from Queue import *

import psyco
psyco.full()

dirs = [[0,0,1],[1,1,0],[2,0,-1],[3,-1,0]]

def moves(dist,x,y,p1,p2):
	global m
	res = []
	p = [p1,p2]
	for d,dx,dy in dirs:
		if m[y+dy][x+dx] == ".":
			res.append((dist+1,x+dx,y+dy,p1,p2))
		else:
			for i in range(2):
				if p[i][0]==x+dx and \
					p[i][1]==y+dy and \
					d == (p[i][2]+2)%4 and\
					p[1-i][2]>=0:
		        		res.append((dist+1,p[1-i][0]+dirs[p[1-i][2]][1],
						p[1-i][1]+dirs[p[1-i][2]][2],p1,p2))
	for d,dx,dy in dirs:
		wx = x
		wy = y
		while m[wy][wx]==".":
			wx+=dx
			wy+=dy
		newP = (wx,wy,(d+2)%4)
		if newP!=p1:
			res.append((dist,x,y,p1,newP))
		if newP!=p2:
			res.append((dist,x,y,newP,p2))
	return res

def norm(p):
	if p[3]<p[4]:
		return p
	else:
		return (p[0],p[1],p[2],p[4],p[3])

def solve():
	global m
	r,c = map(int,getLine().split(" "))
	m = []
	for i in range(r):
		m.append([])
		s = getLine()
		for j in range(c):
			m[-1].append(s[j])
			if s[j] == "O":
				startX = j
				startY = i
				m[-1][-1]="."
			elif s[j]=="X":
				endX = j
				endY = i
				m[-1][-1]="."
	for i in range(r):
		m[i] = ["#"]+m[i]+["#"]
	m = [["#"]*(c+2)]+m+[["#"]*(c+2)]
	startX += 1
	startY += 1
	endX += 1
	endY += 1

	print "going to ",endX,endY

	print m
	pos = (0,startX,startY,(-10,-10,-10),(-10,-10,-10))
	print pos
#	for p in moves(*pos):
#		print p
	visited = set()
	worklist = Queue()
	worklist.put(pos)
	visdist = {}
	while not worklist.empty():
		p = worklist.get()
		if visdist.get(p[1:5],100000)<=p[0]:
			continue
		visdist[p[1:5]]=p[0]
		for p1 in moves(*(p[:5])):
			p2 = norm(p1)
			if visdist.get(p2[1:5],100000)>p2[0]:
				worklist.put(p2)
	res = 100000
	for p in visdist.keys():
		if p[0] == endX and p[1]== endY:
			res = min(res,visdist[p])
	if res<100000:
		return str(res)
	return "THE CAKE IS A LIE"



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
