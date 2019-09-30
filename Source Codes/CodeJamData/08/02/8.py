#!/usr/bin/env python

import sys, operator

def convert_to_minutes(T):
	h, m = T.split(":")
	return 60*int(h)+int(m)

lines = sys.stdin.readlines()

N = lines.pop(0)
for case_iterator in range(int(N)):
	A = []
	B = []
	T = int(lines.pop(0))
	(NA, NB) = lines.pop(0).split(" ")

	for NA_iterator in range(int(NA)):
		(T_leave_A, T_reach_B) = lines.pop(0).split(" ")
		B.append((convert_to_minutes(T_reach_B) + T, -1))
		A.append((convert_to_minutes(T_leave_A), +1))

	for NB_iterator in range(int(NB)):
		(T_leave_B, T_reach_A) = lines.pop(0).split(" ")
		A.append((convert_to_minutes(T_reach_A) + T, -1))
		B.append((convert_to_minutes(T_leave_B), +1))

	A = sorted(A, key=operator.itemgetter(1)) # this is tricky :-D 
	A = sorted(A, key=operator.itemgetter(0))
	Atrains = 0
	count = 0
	for item in A:
		count = count + item[1]
		if count > Atrains:
			Atrains = count

	B = sorted(B, key=operator.itemgetter(1)) # this is tricky :-D 
	B = sorted(B, key=operator.itemgetter(0))
	Btrains = 0
	count = 0
	for item in B:
		count = count + item[1]
		if count > Btrains:
			Btrains = count

	print "Case #"+str(case_iterator+1)+": "+str(Atrains)+" "+str(Btrains)
