#!/usr/bin/python2.5
import sys
import math

inputName = "test.in" if (len(sys.argv) < 2) else sys.argv[1]
file = open(inputName, "r")

def readline(): return file.readline().strip(" \n")

for case in range(int(readline())) :
	n, m, X, Y, Z  = map(int, readline().split())
	
	Speed = [0] * n
	A = [0] * m
	
	for i in range(m):
		A[i] = int(readline())
	

	for i in range(n):
		Speed[i] = A[i% m]
		A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z

#	print Speed

	res = [1] * n

	for i in range(n):
		for j in range(i):
			if Speed[i] > Speed[j]:
				res[i] = res[i] + res[j]
		
		if (res[i] >= 1000000007):
			res[i] = res[i] % 1000000007


	print "Case #%s: %s" % (case + 1, sum(res) % 1000000007)
	

	