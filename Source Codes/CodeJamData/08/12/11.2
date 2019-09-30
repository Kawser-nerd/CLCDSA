#!/usr/bin/python

import sys

inputfile = open(sys.argv[1], 'r').read().split('\n')
outputfile = open("./output.small.2", 'w')

numcases = int(inputfile[0])
totallines = 1
currcase = 0

while currcase < numcases:
	maltdict = {}
	ctofdict = {}	

	flavors = int(inputfile[totallines])
	totallines += 1
	customers = int(inputfile[totallines])
	totallines += 1

	i = 0
	while i < customers:
		currline = inputfile[totallines + i]
		preflist = currline.split(' ')
		numprefs = int(preflist[0])
		preflist = preflist[1:]
		j = 0
		while j < len(preflist):
			flavor = int(preflist[j]) - 1
			preference = int(preflist[j + 1])
			if preference:
				maltdict[i] = flavor
			else:
				ctofdict[i] = ctofdict.setdefault(i, []) + [flavor]

			j += 2
		i += 1
	totallines += i

	impossible = 0
	done = 0
	finaldict = {}
	satisfied = {}

	while not impossible and not done:

		minlen = flavors + 1
		mincustomer = -1
		i = 0
		while i < customers:
			if satisfied.setdefault(i, 0):
				i += 1
				continue
			if len(ctofdict.setdefault(i, [])) < minlen:
				mincustomer = i
				minlen = len(ctofdict.setdefault(i, []))
			i += 1
	
		if minlen > 0:
			f = 0
			outputfile.write("Case #" + str(currcase + 1) + ": ")
			while f < flavors - 1:
				outputfile.write(str(finaldict.setdefault(f, 0)) + " ")
				f += 1
			outputfile.write(str(finaldict.setdefault(f, 0)) + '\n')
			done = 1
	
		else:
			needmalt = maltdict.setdefault(mincustomer, -1)
			if needmalt == -1:
				impossible = 1
			else:
				satisfied[mincustomer] = 1
				finaldict[needmalt] = 1
				for key in ctofdict.keys():
					oks = ctofdict[key]
					if needmalt in oks:
						ctofdict[key].remove(needmalt)

	currcase += 1
	if impossible:
		outputfile.write("Case #" + str(currcase) + ": IMPOSSIBLE\n")