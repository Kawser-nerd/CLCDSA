#!/usr/bin/env python

FILE_NAME_BASE = 'D-small-attempt1'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

from itertools import product

def parse(inp):
	rows, cols = (int(x) for x in inp.readline().split())
	return rows, cols

def rotateGrid(grid, rot):
	return tuple((ring[rot:] + ring[:rot]) for ring in grid)

def solve(rows, cols):
	modulo = 1000000007

	# 0 is disallowed
	# 4 is impossible
	# so only 1, 2 and 3 can be used
	edgeRings = []
	innerRings = []
	for ring in product((1, 2, 3), repeat=cols):
		possible = True
		expect = []
		for i in xrange(cols):
			c = ring[i]
			p = ring[(i - 1) % cols]
			n = ring[(i + 1) % cols]
			same = (p == c) + (n == c)
			expect.append((c, c - same))
		expect = tuple(expect)
		if all(0 <= count <= 2 for val, count in expect):
			innerRings.append(expect)
			if all(count <= 1 for val, count in expect):
				edgeRings.append(expect)
	print cols, len(edgeRings), len(innerRings)

	solutions = []
	def rec(prevRings, left):
		rings = edgeRings if left == 1 else innerRings
		maxCount = 0 if left == 1 else 1
		for ring in rings:
			nextRing = []
			for (hv, hc), (uv, uc) in zip(ring, prevRings[-1]):
				if uc == 0:
					if hv == uv:
						break
				elif uc == 1:
					if hv != uv:
						break
					if hc == 0:
						break
					hc -= 1
				else:
					assert False, uc
				if hc > maxCount:
					break
				nextRing.append((hv, hc))
			else:
				recRings = prevRings + [nextRing]
				if left == 1:
					grid = tuple(
						tuple(val for val, count in ring)
						for ring in recRings
						)
					solutions.append(grid)
				else:
					rec(recRings, left - 1)
	for ring in edgeRings:
		rec([ring], rows - 1)

	uniqueSolutions = set()
	for grid in solutions:
		if all(
				rotateGrid(grid, rot) not in uniqueSolutions
				for rot in xrange(cols)
				):
			uniqueSolutions.add(grid)

	total = len(uniqueSolutions)
	return total % modulo

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	with open(FILE_NAME_BASE + '.in', 'r') as inp:
		numCases = int(inp.readline())
		inputs = [parse(inp) for _ in xrange(numCases)]

	if NUM_PROCESSES == 0:
		runners = [lambda inp=inp: apply(solve, inp) for inp in inputs]
	else:
		from multiprocessing import Pool
		from signal import SIGINT, SIG_IGN, signal
		pool = Pool(NUM_PROCESSES, signal, (SIGINT, SIG_IGN))
		runners = [pool.apply_async(solve, inp).get for inp in inputs]
		pool.close()

	caseFmt = '%' + str(len(str(numCases))) + 'd'
	progressFmt = '[%s/%s] %%s\n' % (caseFmt, caseFmt)
	with open(FILE_NAME_BASE + '.out', 'w') as out:
		for case, runner in enumerate(runners, 1):
			result = runner()
			out.write('Case #%d: %s\n' % (case, result))
			out.flush()
			sys.stderr.write(progressFmt % (case, numCases, result))

if __name__ == '__main__':
	main()
