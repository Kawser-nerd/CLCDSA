#!/usr/bin/env python

FILE_NAME_BASE = 'B-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

from collections import defaultdict

def parse(inp):
	n, x, y = (int(x) for x in inp.readline().split())
	return n, x, y

def solve(num, buyX, buyY):

	freq = defaultdict(float)

	mid = num + 1
	freq[tuple((x - mid) % 2 for x in xrange(mid * 2 + 1))] = 1.0

	#print '-' * 80
	for _ in xrange(num):
		#print freq
		newFreq = defaultdict(float)
		for height, chance in freq.iteritems():
			def fall(x, chance):
				l = height[x - 1]
				c = height[x]
				r = height[x + 1]

				if l == c - 1:
					fl = True
				elif l == c + 1:
					fl = False
				else:
					assert False, height
				if r == c - 1:
					fr = True
				elif r == c + 1:
					fr = False
				else:
					assert False, height

				if fl and fr: # fall random
					fall(x - 1, chance / 2)
					fall(x + 1, chance / 2)
				elif fl: # fall left
					fall(x - 1, chance)
				elif fr: # fall right
					fall(x + 1, chance)
				else: # stay here
					newHeight = list(height)
					newHeight[x] += 2
					newFreq[tuple(newHeight)] += chance

			fall(mid, chance)
		freq = newFreq

	if -mid <= buyX <= mid:
		return sum(
			chance
			for height, chance in freq.iteritems()
			if buyY < height[buyX + mid]
			)
	else:
		return 0.0

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

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

if __name__ == '__main__':
	main()
