#!/usr/bin/python

import sys


if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		n = int(sys.stdin.readline())
		plate = map(int, sys.stdin.readline().split())
		# plate.sort()
		# plate.reverse()
		mintime = 10000
		for ct in range(1,1001):
			sptime = 0
			for a in plate:
				sptime = sptime + (a-1)/ct
			mintime = min(mintime, ct+sptime)

		print "Case #{}: {}".format(t+1, mintime)