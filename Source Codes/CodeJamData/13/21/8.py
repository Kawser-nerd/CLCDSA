#!/usr/bin/env python

FILE_NAME_BASE = 'A-large'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	start, num = (int(x) for x in inp.readline().split())
	motes = tuple(int(x) for x in inp.readline().split())
	assert len(motes) == num
	return start, motes

def solve(start, motes):
	motes = sorted(motes)
	num = len(motes)

	best = num
	size = start
	added = 0
	i = 0
	while i < num:
		if motes[i] < size:
			size += motes[i]
			i += 1
		else:
			# Option: delete the rest.
			best = min(best, added + num - i)
			# Option: add mote.
			if size <= 1:
				break
			else:
				while motes[i] - size >= 0:
					size += size - 1
					added += 1
	else:
		best = min(best, added)

	return best

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
