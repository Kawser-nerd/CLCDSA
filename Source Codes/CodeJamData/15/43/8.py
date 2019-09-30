#!/usr/bin/env python

FILE_NAME_BASE = 'C-small-attempt0'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

from itertools import combinations

def parse(inp):
	numSentences = int(inp.readline())
	sentences = tuple(
		inp.readline().split()
		for _ in xrange(numSentences)
		)
	return sentences,

def subsets(sequence):
	'''Iterates through all subsets of the given sequence.
	Each yielded element is a tuple containing a subset of the elements of
	the original sequence, in the same order as in the original sequence.
	'''
	sequence = tuple(sequence)
	size = len(sequence)
	def rec(s, i):
		if i == size:
			yield tuple(s)
		else:
			s.append(sequence[i])
			for sub in rec(s, i + 1):
				yield sub
			del s[-1]
			for sub in rec(s, i + 1):
				yield sub
	return rec([], 0)

def solve(sentences):
	# Convert strings to integers.
	words = {}
	for sentence in sentences:
		for word in sentence:
			if word not in words:
				words[word] = len(words)
	sentences = tuple(
		set(words[word] for word in sentence)
		for sentence in sentences
		)

	enWords = sentences[0]
	frWords = sentences[1]

	minBiling = len(words)
	for enSentenceIndices in subsets(xrange(2, len(sentences))):
		enWords = set()
		frWords = set()
		for idx in xrange(len(sentences)):
			if idx == 0 or idx in enSentenceIndices:
				enWords |= sentences[idx]
			else:
				frWords |= sentences[idx]
		minBiling = min(minBiling, len(enWords & frWords))
	return minBiling

	# Every pair in sameLang are words that occur in the same language.
	sameLang = set()
	for sentence in sentences:
		for pair in combinations(sorted(sentence), 2):
			sameLang.add(pair)

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
