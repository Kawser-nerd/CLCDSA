# -*- coding: utf-8 -*-
from math import *

fin = open("a-large.in")
fout = open("a-large.out","w")
cases= int(fin.readline().split()[0])
case = 0

def answer(x):
	global case, cases
	case += 1
	print >>fout, "Case #"+str(case)+": "+str(x)
	print "Case #"+str(case)+": "+str(x)
	
for test in xrange(cases):
	orange=1
	blue=1
	lastblue=0
	lastorange=0
	cont= 0
	s= fin.readline().split()
	n = int(s[0])
	for i in xrange(n):
		if s[2*i+1]=='O':
			move = abs(int(s[2*i+2])-orange)-(cont-lastorange)
			if move<0:
				move=0
			cont=cont+move+1
			lastorange= cont
			orange=int(s[2*i+2])
		if s[2*i+1] =='B':
			move = abs(int(s[2*i+2])-blue)-(cont-lastblue)
			if move<0:
				move=0
			cont=cont+move+1
			lastblue= cont
			blue=int(s[2*i+2])
	answer(str(cont))	
	
