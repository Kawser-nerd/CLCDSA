# -*- coding: utf-8 -*-
from math import *

fin = open("d-large.in")
fout = open("d-large.out","w")
cases= int(fin.readline().split()[0])
case = 0

def answer(x):
	global case, cases
	case += 1
	print >>fout, "Case #"+str(case)+": "+str(x)
	print "Case #"+str(case)+": "+str(x)
	
for test in xrange(cases):
	n= int(fin.readline().split()[0])
	array= map(int, fin.readline().split())
	sarray=sorted(array)
	cont=0
	for i in xrange(n):
		if not (array[i]==sarray[i]):
			cont+=1
	answer(str(cont)+'.000000')	
	
