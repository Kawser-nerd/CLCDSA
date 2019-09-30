# -*- coding: utf-8 -*-
from math import *

fin = open("b-large.in")
fout = open("b-large.out","w")
cases= int(fin.readline().split()[0])
case = 0

def answer(x):
	global case, cases
	case += 1
	print >>fout, "Case #"+str(case)+": "+str(x)
	print "Case #"+str(case)+": "+str(x)
	
for test in xrange(cases):
	s= fin.readline().split()
	p = 0
	invoke={}
	opposed={}
	c= int(s[p])
	for i in xrange(c):
		p+=1
		aux = s[p]
		invoke[aux[0]+aux[1]]=aux[2]
		invoke[aux[1]+aux[0]]=aux[2]
	p+=1
	d=int(s[p])
	for i in xrange(d):
		p+=1
		aux=s[p]
		if aux[0] not in opposed:
			opposed[aux[0]]=[]
		if aux[1] not in opposed:
			opposed[aux[1]]=[]
		opposed[aux[0]].append(aux[1])
		opposed[aux[1]].append(aux[0])
	p+=1
	n =int(s[p])
	p+=1
	series =s[p]
	seriesout=[series[0]]
	for i in xrange(n-1):
		if not seriesout:
			seriesout.append(series[i+1])
			continue
		if series[i+1]+seriesout[-1] in invoke:
			seriesout[-1]=invoke[series[i+1]+seriesout[-1]]
			continue
		if series[i+1] in opposed:
			if not set(opposed[series[i+1]]).isdisjoint(set(seriesout)):
				seriesout=[]
				continue
		seriesout.append(series[i+1])
	answer(str(seriesout).replace('\'',''))	
	
