#!/usr/bin/env python

FILE_NAME_BASE = 'C-large'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	maxSame, numOld, maxValue = (int(x) for x in inp.readline().split())
	oldCoins = tuple(int(x) for x in inp.readline().split())
	assert len(oldCoins) == numOld
	return oldCoins, maxSame, maxValue

def solve(coins, maxSame, maxValue):
	added = 0
	coinIdx = 0
	reach = 0
	# coins [0..coinIdx) have been used
	# all numbers [1..reach] can be made
	while reach < maxValue:
		if coinIdx < len(coins):
			coin = coins[coinIdx]
		else:
			coin = None
		target = reach + 1
		if coin is None or coin > target:
			# New coin.
			coin = target
			added += 1
		else:
			coinIdx += 1
		# Extend range.
		reach += coin * maxSame

	return added

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
