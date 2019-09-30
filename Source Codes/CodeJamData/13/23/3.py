#!/usr/bin/env python

FILE_NAME_BASE = 'C-large'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def insertWord(node, word):
	if node is None:
		node = [ None ] * 27
	if word:
		ch = ord(word[0]) - ord('a')
		node[ch] = insertWord(node[ch], word[1 : ])
		return node
	else:
		node[26] = True
		return node

def initTree():
	global tree
	root = None
	for word in words:
		root = insertWord(root, word)
	tree = root

def readDict():
	global words
	words = []
	inp = open('garbled_email_dictionary.txt', 'r')
	for line in inp.readlines():
		words.append(line.rstrip())
	inp.close()

def parse(inp):
	email = inp.readline().rstrip()
	return email,

def solve(email):
	email = tuple(ord(c) - ord('a') for c in email)
	length = len(email)
	#print email

	states = [ set() for _ in xrange(length + 1) ]
	states[0].add((0, 0))

	def tryMatch(i, node, changes, nextChange):
		if node[26]:
			# Word can end here.
			states[i].add((changes, nextChange))
		if i < length:
			ch = email[i]
			subNode = node[ch]
			# Matching char.
			if subNode is not None:
				tryMatch(i + 1, subNode, changes, nextChange)
			# Change char.
			if i >= nextChange:
				for alt in xrange(26):
					if alt == ch:
						continue
					subNode = node[alt]
					if subNode is not None:
						tryMatch(i + 1, subNode, changes + 1, i + 5)

	for i in xrange(length):
		#print i, states[i]
		# Earlier nextChange is always better.
		best = {}
		for changes, nextChange in states[i]:
			prev = best.get(changes)
			if prev is None:
				best[changes] = nextChange
			else:
				if nextChange < prev:
					best[changes] = nextChange

		for changes, nextChange in best.iteritems():
			tryMatch(i, tree, changes, nextChange)
	#print '.', states[length]

	return min(changes for changes, nextChange in states[length])

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	readDict()
	initTree()

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
