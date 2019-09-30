#!/usr/bin/env python

FILE_NAME_BASE = 'B-small-attempt0'
NUM_PROCESSES = 0

from itertools import izip

def parse(inp):
	delCost, insCost, threshold, length = (
		int(x) for x in inp.readline().split()
		)
	pixels = tuple(
		int(x) for x in inp.readline().split()
		)
	assert len(pixels) == length
	#pixelStr = ''.join(chr(pixel) for pixel in pixels)
	return pixels, delCost, insCost, threshold

def solve(pixels, delCost, insCost, threshold):
	# Deleting everything is cheaper than this.
	infinity = delCost * len(pixels) + 1
	# best[i] = cumulative cost to get to previous pixel value i,
	#           where the sequence up to now is smooth
	best = [0] * 256
	for pixel in pixels:
		#print pixel, best
		# When deleting we skip this pixel, so we're still at the same
		# pixel value as before.
		delBest = [cost + delCost for cost in best]
		# When inserting we have to create a transition sequence that is smooth.
		# The result value is the value of the input pixel.
		insBest = [infinity] * 256
		cost = infinity
		for oldValue in xrange(256):
			delta = abs(pixel - oldValue)
			if threshold == 0:
				if delta == 0:
					numInserts = 0
				else:
					continue
			else:
				numInserts = max(0, (delta - 1) / threshold)
			cost = min(cost, best[oldValue] + insCost * numInserts)
		insBest[pixel] = cost
		# When using the previous value, the cost depends on the delta.
		changeBest = [None] * 256
		for newValue in xrange(256):
			cost = infinity
			for oldValue in xrange(256):
				if abs(oldValue - newValue) <= threshold:
					# Transition is smooth.
					cost = min(cost, best[oldValue] + abs(newValue - pixel))
			changeBest[newValue] = cost
		best = [ min(costs) for costs in izip(insBest, delBest, changeBest) ]
	# End pixel value doesn't matter; pick cheapest.
	return min(best)

if __name__ == '__main__':
	inp = open(FILE_NAME_BASE + '.in', 'r')
	numCases = int(inp.readline())
	if NUM_PROCESSES == 0:
		results = [
			solve(*parse(inp))
			for _ in range(numCases)
			]
	else:
		from multiprocessing import Pool
		pool = Pool(NUM_PROCESSES)
		results = [
			pool.apply_async(solve, parse(inp))
			for _ in range(numCases)
			]
	inp.close()
	out = open(FILE_NAME_BASE + '.out', 'w')
	for case, result in enumerate(results):
		value = result if NUM_PROCESSES == 0 else result.get()
		out.write('Case #%d: %s\n' % (case + 1, value))
		out.flush()
	out.close()
