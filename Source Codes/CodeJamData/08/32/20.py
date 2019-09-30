#!/usr/bin/env python

from string import split, join, strip
from sys import argv, stdin, exit
from math import hypot
from copy import copy
from getopt import getopt
from misc import *
import os.path
import psyco
psyco.full()



def solve(case):
	ns = case[0]
	ugly_count = 0
	prim = [2,3,5,7]

	for test in weird_iter(ns):
		if (test == 0):
			ugly_count = ugly_count + 1
			continue

		test = abs(test)

		if (test == 1):
			continue
		
		for p in prim:
			if (test % p == 0):
				ugly_count = ugly_count + 1
				break

	return str(ugly_count)





def weird_iter(ns):
	ni = int(ns)
	nl = len(ns)
	
	yield ni
	
	for i in range(1,nl):
		ni = int(ns[:i])
		for x in weird_iter(ns[i:]):
			yield (ni + x)
			yield (ni - x)



def main():
	(max_cases, specific_case) = args(argv)

	cases = int(get_line())

	if (max_cases):
		cases = max_cases

	for c in range(1, cases+1):
		cd = []

		LINES_PER_CASE = 1

		for de_nada in range(LINES_PER_CASE):
			cd.append(get_line())
			
		if (specific_case):
			if (c != specific_case):
				continue
			else:
				print cd

		sol = 'Case #' + str(c) + ": " + solve(cd)

		put_line(sol)		
		
		print sol


def get_line():
	global file_in
	return strip(file_in.readline())


def put_line(line):
	global file_out
	if (file_out):
		file_out.write(line + '\n')
	
	
def args(arg_v):
	global file_in
	global file_out

	go = getopt(argv[1:], 'i:o:c:m:')
	
	file_in = None
	file_out = None
	max_cases = None
	specific_case = None
	
	for o in go[0]:
		if (o[0] == '-i'):
			file_in = open(o[1])
		elif (o[0] == '-o'):
			#assert(not os.path.isfile(o[1]))
			file_out = open(o[1], 'w')
		elif (o[0] == '-c'):
			specific_case = int(o[1])
		elif (o[0] == '-m'):
			max_cases = int(o[1])

	assert(file_in)
	
	return (max_cases, specific_case)


main()


