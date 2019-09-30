# -*- coding: utf-8 -*-
from math import *

fin = open("c-large.in")
fout = open("c-large.out","w")
cases= int(fin.readline().split()[0])
case = 0

def answer(x):
	global case, cases
	case += 1
	print >>fout, "Case #"+str(case)+": "+str(x)
	print "Case #"+str(case)+": "+str(x)
	

def nim(x):
	aux=0
	for i in x:
		aux=aux^i
	return aux
	
for test in xrange(cases):
	n= int(fin.readline().split()[0])
	bag= map(int, fin.readline().split())
	if nim(bag)==0:
		answer(str(sum(bag)-min(bag)))
	else:
		answer("NO")
	
