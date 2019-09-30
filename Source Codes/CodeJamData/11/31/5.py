#!/usr/bin/env python3.1

from __future__ import division

import sys

def calc(numLines, line):
	ok = True
	while ok:
		ok = False
		for i in range(len(line)):
			f = line[i].find("#")
			if f >= 0:
				if i == len(line) - 1 or f == len(line[i]) - 1 or line[i][f:f+2] != "##" or line[i+1][f:f+2] != "##":
					print "Impossible"
					return
				line[i] = line[i][:f] + "/\\" + line[i][f+2:]
				line[i+1] = line[i+1][:f] + "\\/" + line[i+1][f+2:]
				ok = True
				break
	for l in line:
		print l

def getints():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

numTestCases = getints()[0]
for i in range(numTestCases):
	numLines = getints()
	print("Case #%d:" % (i+1))
	result = calc(numLines, [sys.stdin.readline().strip() for x in range(numLines[0])])

