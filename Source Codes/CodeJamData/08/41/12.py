#!/usr/bin/env python

inf = 1000000000

class InnerNode(object):

	def __init__(self, nodes, index, gate, change):
		self.nodes = nodes
		self.index = index
		self.gate = gate
		self.change = change

	def produces(self):
		left = self.nodes[self.index * 2].produces()
		right = self.nodes[self.index * 2 + 1].produces()

		orProd = (left[0] + right[0], min(left[1], right[1]))
		andProd = (min(left[0], right[0]), left[1] + right[1])

		if self.gate:
			norm, alt = andProd, orProd
		else:
			norm, alt = orProd, andProd
		if self.change:
			return ( min(norm[0], alt[0] + 1), min(norm[1], alt[1] + 1) )
		else:
			return norm

class LeafNode(object):

	def __init__(self, value):
		self.value = value

	def produces(self):
		return (inf, 0) if self.value else (0, inf)

def solve():
	M, V = [ int(i) for i in raw_input().split() ]
	nodes = [ None ] * (M + 1)
	for i in range(0, (M - 1) / 2):
		G, C = [ int(j) for j in raw_input().split() ]
		nodes[i + 1] = InnerNode(nodes, i + 1, G, bool(C))
	for i in range(0, (M + 1) / 2):
		nodes[(M - 1) / 2 + i + 1] = LeafNode(int(raw_input()))
	minChange = nodes[1].produces()[V]
	#for i in range((M - 1) / 2 + (M + 1) / 2):
	#	print i + 1, nodes[i + 1].produces()
	return 'IMPOSSIBLE' if minChange >= inf else minChange

for case in range(int(raw_input())):
	print 'Case #%d: %s' % (case + 1, solve())
