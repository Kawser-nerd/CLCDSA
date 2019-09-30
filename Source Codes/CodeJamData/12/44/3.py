#!/usr/bin/env python

FILE_NAME_BASE = 'D-small-attempt0'
NUM_PROCESSES = 4

def parse(inp):
	numRows, numCols = (int(x) for x in inp.readline().split())
	grid = tuple(
		inp.readline().strip()
		for _ in xrange(numRows)
		)
	boolGrid = []
	caves = [ None ] * 10
	assert len(grid) == numRows
	for y, row in enumerate(grid):
		assert len(row) == numCols
		boolRow = []
		for x, c in enumerate(row):
			if c.isdigit():
				i = int(c)
				assert caves[i] is None
				caves[i] = (x, y)
				boolRow.append(True)
			else:
				boolRow.append(c == '.')
		boolGrid.append(tuple(boolRow))
	numCaves = sum(cave is not None for cave in caves)
	assert all(caves[i] is not None for i in xrange(numCaves))
	assert all(caves[i] is None for i in xrange(numCaves, len(caves)))
	return tuple(boolGrid), caves[ : numCaves]

def solve(grid, caves):
	def computeReach(start):
		reach = set()
		newReach = set([ start ])
		while newReach:
			pos = newReach.pop()
			if pos not in reach:
				reach.add(pos)
				x, y = pos
				if grid[y - 1][x]:
					if (x, y - 1) not in reach:
						newReach.add((x, y - 1))
				if grid[y][x - 1]:
					if (x - 1, y) not in reach:
						newReach.add((x - 1, y))
				if grid[y][x + 1]:
					if (x + 1, y) not in reach:
						newReach.add((x + 1, y))
		return reach

	def computeLucky(start):
		def applyMove(positions, dx, dy):
			moved = set()
			for x, y in positions:
				if grid[y + dy][x + dx]:
					x += dx
					y += dy
					if (x, y) not in start:
						return None
				moved.add((x, y))
			return frozenset(moved)

		reach = set()
		newReach = set([ frozenset(start) ])
		while newReach:
			pos = newReach.pop()
			if pos not in reach:
				reach.add(pos)
				moved = applyMove(pos, 0, 1)
				if moved is not None:
					if moved not in reach:
						newReach.add(moved)
				moved = applyMove(pos, -1, 0)
				if moved is not None:
					if moved not in reach:
						newReach.add(moved)
				moved = applyMove(pos, 1, 0)
				if moved is not None:
					if moved not in reach:
						newReach.add(moved)
		return reach

	ret = []
	for cave in caves:
		reachable = computeReach(cave)
		final = computeLucky(reachable)
		lucky = any(
			len(reach) == 1 and reach.__iter__().next() == cave
			for reach in final
			)
		ret.append((len(reachable), lucky))
	return ret

if __name__ == '__main__':
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
		out.write('Case #%d:\n' % (case + 1))
		for i, (reachable, lucky) in enumerate(value):
			out.write('%d: %d %s\n' % (
				i, reachable, 'Lucky' if lucky else 'Unlucky'
				))
		out.flush()
	out.close()
