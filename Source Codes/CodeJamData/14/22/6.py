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



#--------------------------------------------------------------------
def solve():
	ans = 0
	A,B,K = nextints()
	for i in range(A):
		for j in range(B):
			if (i&j)<K:
				ans += 1
	write("%d\n"%ans)
	
	
#--------------------------------------------------------------------
if __name__ == "__main__": ##__name__: [filename].py
	print "Hello, Main."
else:
	global fr, fw
	prob_name = "B-small-attempt0"

	fr = open(prob_name + '.in', 'r')
	fw = open(prob_name + '.out', 'w')
	cas = (int)(fr.readline())
	for cs in range(cas):
		write("Case #%d: " % (cs+1) )
		solve()
	fr.close()
	fw.close()
#--------------------------------------------------------------------


