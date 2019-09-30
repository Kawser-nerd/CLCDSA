#!/usr/bin/env python

import collections
import heapq

def possible(Wormholes, Goal, Node, Have):
	# can you use Node to get to Goal without anything from Have
	connected = Wormholes[Node] - Have
	if Goal in connected:
		return True

	seen = set()

	while len(connected) > 0:
		item = connected.pop()
		seen.add(item)
		connected = connected.union(set(Wormholes[item]) - Have - seen)
		if Goal in connected:
			return True

	return Goal in connected

def solve(P,W,Wraw):
	Wormholes = collections.defaultdict(set)
	for start, end in Wraw:
		Wormholes[start].add(end)
		Wormholes[end].add(start)


	if 1 in Wormholes[0]:
		return "0 " + str(len(Wormholes[0]))

	minCost = 100000
	mostAttackable = 0

	print
#	for key,value in Wormholes.items():
#		print key, value
	print

	routes = [(0, set([0]), set(Wormholes[0]), set(Wormholes[0]))]
	while len(routes) > 0:
		lowestCost, have, last, attackable = heapq.heappop(routes)

#		print "\t", have, last

		for toConquer in last:
#			if not possible(Wormholes, 1, toConquer, have):
#				print "notUseful", toConquer, have
#				continue

#			print "\t\t", toConquer

			newHave = have.union(set([toConquer]))
			newAttackable = attackable.union(Wormholes[toConquer] - have)
			newAttackable.remove(toConquer)

#			print "\t\t\t", newHave, newAttackable

			if (lowestCost + 1) > minCost:
				return str(minCost) + ' ' + str(mostAttackable)
			elif ((lowestCost + 1) == minCost) and (1 in newAttackable):
				mostAttackable = max(mostAttackable, len(newAttackable))
			elif ((lowestCost + 1) < minCost) and (1 in newAttackable):
				minCost = lowestCost + 1
				mostAttackable = len(newAttackable)
				print "can be in position for cost:", minCost, "with", mostAttackable, "to attack"

			heapq.heappush(routes, (lowestCost + 1, newHave, Wormholes[toConquer] - newHave, newAttackable))

#	assert minCost < 10000
	return str(minCost) + ' ' + str(mostAttackable)


def solveFile(Filename):
	inFile = open(Filename, "r")
	outFile = open(Filename[:-2]+"out", "w")
	tests = int(inFile.readline())
	for test in xrange(tests):
		P, W = map(int, inFile.readline().strip().split())
		Ws = [map(int, item.split(',')) for item in inFile.readline().strip().split(' ')]

		outFile.write("Case #{0}: {1}\n".format(test+1, solve(P,W,Ws)))

solveFile("example.in")
solveFile("D-small-attempt2.in")
#solveFile("D-large.in")
