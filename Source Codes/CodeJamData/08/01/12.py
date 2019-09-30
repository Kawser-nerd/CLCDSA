#!/usr/bin/env python2.5

import sys
infile = open(sys.argv[1], 'rb')
numcases = int(infile.readline())
currengine = ''
for case in xrange(1, numcases+1):
#	print "case", case
	numengines = int(infile.readline())
#	print "numengines", numengines
	engines = [infile.readline().strip() for x in xrange(numengines)]
#	print engines
	numqueries = int(infile.readline())
#	print "numqueries", numqueries
	queries = [infile.readline().strip() for x in xrange(numqueries)]
#	print queries
	i=0
	switches = 0
	while 1:
		q = queries[i:]
		long = 0
		for e in engines:
			if e == currengine: continue
			try: 
				l = q.index(e)
			except:
				i=numqueries
				break
			if l > long: long = l
		if i >= numqueries:
			break
		switches += 1
		currengine = queries[i+long]
		i = i+long+1
	print "Case #" + str(case) + ": " + str(switches)