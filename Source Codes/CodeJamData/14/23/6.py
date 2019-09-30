# -*- coding: utf-8 -*-
# Google Code Jam
# Create Date: 2014-04-10
# Created by: buaamm
#--------------------------------------------------------------------
import sys
import os

def nextint():
	return (int)(fr.readline())

def nextints():
	return map(int, next().strip().split())
	
def next():
	return fr.readline()

def write(s):
	fw.write(str(s))
	
def writeline(s):
	fw.write(str(s) + "\n")

def repeat(s, r):
	for i in range(r):
		fw.write(s)

def reprep(s, len, r):
	for i in range(r):
		repeat(s, len)
		write("\n")

def draw_single(n,m):
	write("c")
	repeat("*", m-1)
	write("\n")
	reprep("*", m, n-1)
def draw_line(a,b):
	repeat(".", a)
	repeat("*", b)
	write("\n")


def dfs(p, v):
	for i in range(n):
		if g[p][i]==1 and v[i]==0:
			v[i] = 1
			dfs(i,v)

def check(index):
	v = vis[:]
	for i in range(index):
		v[ path[i] ] = 0
	#print "DEBUG",
	#print v[:n]
	dfs(path[index], v)
	if sum(v[:n]) == n:
		return True
	else:
		return False
#--------------------------------------------------------------------
def solve():
	global vis, g, n, code, F, path, path_len, avail
	code = [0] * 100
	g = [0] * 100
	vis = [0] * 100
	avail = [0] * 100
	for i in range(100):
		g[i] = [0] * 100;
	n, m = nextints()
	for i in range(n):
		code[i] = nextint()
	F = zip(code, range(n))
	F.sort()
	for i in F:
		print i[0], i[1]
	#---------------------------
	for i in range(m):
		a, b = nextints()
		a=a-1
		b=b-1
		g[a][b], g[b][a] = 1, 1
	path = [0]*100
	path_len = 1
	path[0] = F[0][1]
	avail[0] = True
	vis[ path[0] ] = 1
	write(code[ path[0] ])
	#ROOT ok
	
	for index in range(n-1):
		#print "START---------------"
		#find next
		#UPDATE
		AV = [0] * n
		for k in range(path_len):
			if not check(k):
				avail[k] = False
			else:
				avail[k] = True
				for i in range(n):
					if g[i][ path[k] ]:
						AV[i] = 1
			##print "AVAIL = ",
			##print avail[:path_len]
		
		for x in range(n):
			p = F[x][1]
			if (not vis[p]) and AV[p]:
				vis[p] = 1
				write(str(F[x][0]))
				# find port
				##print p
				new_len = path_len
				for k in range(path_len):
					u = path_len - k - 1
					##print u
					if g[path[u]][p] == 1:
						path[ new_len ] = p
						new_len += 1
						break
					else:
						new_len -= 1
				path_len = new_len
				#print "DEBUG" + str(path_len)
				break
				
				
		
	

	write("\n")
	#if cnt == 0:
	#	write("Volunteer cheated!\n")
	#elif cnt > 1:
	#	write("Bad magician!\n")
	
	
#--------------------------------------------------------------------
if __name__ == "__main__": ##__name__: [filename].py
	print "Hello, Main."
else:
	global fr, fw
	prob_name = "C-large"

	fr = open(prob_name + '.in', 'r')
	fw = open(prob_name + '.out', 'w')
	cas = (int)(fr.readline())
	for cs in range(cas):
		write("Case #%d: " % (cs+1) )
		solve()
	fr.close()
	fw.close()
#--------------------------------------------------------------------


