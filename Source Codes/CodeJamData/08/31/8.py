#!/usr/bin/python2.5
import sys
import math

inputName = "test.in" if (len(sys.argv) < 2) else sys.argv[1]
file = open(inputName, "r")

def readline(): return file.readline().strip(" \n")

for case in range(int(readline())) :
	P, K, L  = map(int, readline().split())
	
	Letters = map(int, readline().split())
	Letters.sort(reverse=True)
	
	res = 0
	i = 1
	z = 0
	for e in Letters:
		res = res + i * e
		z += 1
		if (z >= K):
			z = 0
			i += 1
	
	
	

	#print (P, K, L, Letters)
	

	print "Case #%s: %s" % (case + 1, res)
	

	