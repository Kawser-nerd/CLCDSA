#!/usr/bin/python
#
# GCJ 2014, Round 2
# Task 'D' by Veselin Georgiev
#

computed = {}

def prefixLen_real(s1, s2):
	i = 0
	while i < len(s1) and i < len(s2) and s1[i] == s2[i]:
		i += 1
	return i

def prefixLen(s1, s2):
	global computed
	key = (s1, s2)
	if key not in computed:
		computed[key] = prefixLen_real(s1, s2)
	return computed[key]

class Trie(object):
	def __init__(self):
		self.t = []
		self.numNodes = 0
	
	def add(self, s):
		if not self.t:
			self.numNodes += 1 # for the ""
		maxPrefixLen = 0
		for hs in self.t:
			maxPrefixLen = max(maxPrefixLen, prefixLen(hs, s))
		self.t.append(s)
		self.numNodes += len(s) - maxPrefixLen

def solve():
	m, n = map(int, raw_input().strip().split())
	S = []
	for i in xrange(m):
		S.append(raw_input().strip())
	worstNumNodes = -1
	numCases = 0
	
	for IT in xrange(n ** m):
		servers = [Trie() for i in xrange(n)]
		t = IT
		for i in xrange(m):
			serverId = t % n
			t /= n
			servers[serverId].add(S[i])
		numNodes = 0
		for i in xrange(n):
			numNodes += servers[i].numNodes
		if numNodes > worstNumNodes:
			worstNumNodes = numNodes
			numCases = 1
		elif numNodes == worstNumNodes:
			numCases += 1
	return "%d %d" % (worstNumNodes, numCases)

def main():
	nTests = int(raw_input().strip())
	for i in xrange(nTests):
		print "Case #%d:" % (i + 1), solve()
		

if __name__ == "__main__":
	main()
