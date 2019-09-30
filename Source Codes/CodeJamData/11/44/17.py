#!/usr/bin/env python
import sys,math
from pygraph.classes.graph import graph
from collections import defaultdict
infile = sys.argv[1]
#outfile = sys.argv[2]

indata = open(infile, 'r').readlines()
#print indata

numcases = int(indata[0].strip())
lines = [x.strip().split(' ') for x in indata[1:]]


def solve(P, W, Ws):
	g = graph()
	g.add_nodes(range(0, P))
	for w in Ws:
		g.add_edge(w)

	distance = dict()
	visited = dict()
	previous = defaultdict(set)
	for x in g.nodes():
		distance[x] = sys.maxint
		visited[x] = False
	distance[0] = 0
	current = 0

	while True:
		for x in g.neighbors(current):
			if distance[current] + 1 < distance[x]:
				distance[x] = distance[current] + 1
				previous[x] = set([current])
			elif distance[current] + 1 == distance[x]:
				previous[x].add(current)
				
		visited[current] = True

		if len(filter(lambda x: not x, visited.values())) == 0:
			break
		else:
			unvisited = filter(lambda x: visited[x] == False, visited.keys())
			unvisited.sort(key=lambda x: distance[x])
			#print unvisited
			current = unvisited[0]


	paths = [[1]]
	for i in range(distance[1]):
		paths = [[x] + p for p in paths for x in previous[p[0]]]
	paths = [p[:-1] for p in paths]


	mostthreatened = [None, 0]
	for p in paths:
		threatened = set()
		for x in p:
			threatened.update(set(g.neighbors(x)).difference(set(p)))
		if len(threatened) > mostthreatened[1]:
			mostthreatened = [p, len(threatened)]
		#print mostthreatened

	#span, dist = shortest_path(g, 1)
	#print span
	#print paths
	return str(distance[1]-1) + " " + str(mostthreatened[1])

for j in range(0, numcases):
	P = int(lines[j*2][0])
	W = int(lines[j*2][1])
	Ws = [[int(x.split(',')[0]), int(x.split(',')[1])] for x in lines[j*2+1]]
	assert(W == len(Ws))
	#print Ws
	answer = solve(P, W, Ws)


	print "Case #" + str(j+1) + ": " + answer
