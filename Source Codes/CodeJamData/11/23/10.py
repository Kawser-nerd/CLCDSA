#!/usr/bin/env python

import itertools

def color(N, rooms):
	smallestRoom = min([len(room) for room in rooms])
	print smallestRoom, rooms

	for numColors in xrange(smallestRoom, 0, -1):
		for coloring in itertools.product(range(1,smallestRoom+1), repeat=N):
			if sorted(set(coloring)) != range(1,smallestRoom+1):
				continue
				
			for room in rooms:
				if len(set([coloring[node-1] for node in room])) != numColors:
					break
			else:
				print coloring, numColors
				return coloring

def solve(N, M, start, end):
	if len(start) == 0:
		return N, range(N)

	rooms = [range(1,N+1)]
	for s, e in zip(start, end):
		for room in rooms:
			if (s in room) and (e in room):
				rooms.remove(room)
				roomUpper = [i for i in room if s <= i <= e]
				roomLower = [i for i in room if not (s < i < e)]
				rooms.append(tuple(roomUpper))
				rooms.append(tuple(roomLower))
				break

	temp = color(N, rooms)
	return len(set(temp)), temp


def solveFile(Filename):
	inFile = open(Filename, "r")
	outFile = open(Filename[:-2]+"out", "w")
	tests = int(inFile.readline())
	for case in xrange(tests):
		N,M = map(int, inFile.readline().strip().split())
		start = map(int, inFile.readline().strip().split())
		end = map(int, inFile.readline().strip().split())
		colors, arrange = solve(N, M, start, end)
		outFile.write("Case #{0}: {1}\n{2}\n".format(case+1, colors, ' '.join(map(str, arrange))))

#solveFile("example.in")
solveFile("C-small-attempt2.in")
#solveFile("B-large.in")

