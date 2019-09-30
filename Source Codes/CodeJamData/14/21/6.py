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


def gen(first):
	S = [0]*200
	C = [0]*200
	S[0] = first[0]
	C[0] = 1
	SZ = 1
	L = len(first)
	for i in range(1,L):
		if first[i] == first[i-1]:
			C[SZ-1] += 1
		else:
			S[SZ] = first[i]
			C[SZ] = 1
			SZ += 1
	return S,C,SZ

#--------------------------------------------------------------------
def solve():
	n = nextint()
	SA = [0]*200
	CA = [0]*200
	SZA = [0]*200
	
	for i in range(n):
		SA[i],CA[i],SZA[i] = gen(next().strip())
	
	flag=True
	for i in range(n-1):
		if SZA[i]!=SZA[i+1] or SA[i]!=SA[i+1]:
			flag=False
			break
	if flag == False:
		write("Fegla Won\n")
		return
	L = SZA[0]
	ans = 0
	for i in range(L):
		arr = []
		for j in range(n):
			arr.append(CA[j][i])
		arr.sort()
		mid = arr[n/2]
		ans += sum( map(lambda x:abs(x-mid),arr) )
	write("%d\n"%ans)
	
	
#--------------------------------------------------------------------
if __name__ == "__main__": ##__name__: [filename].py
	print "Hello, Main."
else:
	global fr, fw
	prob_name = "A-large"

	fr = open(prob_name + '.in', 'r')
	fw = open(prob_name + '.out', 'w')
	cas = (int)(fr.readline())
	for cs in range(cas):
		write("Case #%d: " % (cs+1) )
		solve()
	fr.close()
	fw.close()
#--------------------------------------------------------------------


