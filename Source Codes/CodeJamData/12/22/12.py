#!/usr/bin/env python

FILE_NAME_BASE = 'B-large'
NUM_PROCESSES = 4

def search(low, high, test):
	'''Binary search: [low..high) is the range to search; function "test"
	takes a single value from that interval and returns a truth value.
	The function must be ascending: (test(x) and y >= x) => test(y).
	Returns smallest argument in the interval for which the function is true,
	or "high" if the function is false for the entire interval.
	'''
	while low < high:
		mid = (low + high - 1) / 2
		if test(mid):
			if mid == low:
				return low # found
			high = mid + 1
		else:
			low = mid + 1
	return high # not found

def parse(inp):
	water, rows, cols = (int(x) for x in inp.readline().split())
	ceilings = tuple(
		tuple(int(x) for x in inp.readline().split())
		for _ in xrange(rows)
		)
	assert all(len(ceiling) == cols for ceiling in ceilings)
	floors = tuple(
		tuple(int(x) for x in inp.readline().split())
		for _ in xrange(rows)
		)
	assert all(len(floor) == cols for floor in floors)
	return floors, ceilings, water

def solve(floors, ceilings, water):
	rows = len(ceilings)
	cols = len(ceilings[0])

	# Compute in decaseconds, to avoid floating points.
	#INFINITY = 100000 + 100 * 100 * 100
	INFINITY = 1 << 30

	# Determine when a square will become reachable from each of its neighbours.
	deltas = ((0, -1), (1, 0), (0, 1), (-1, 0))
	reach = []
	for y in xrange(rows):
		reachLine = []
		for x in xrange(cols):
			reachSquare = []
			for dx, dy in deltas:
				nx = x + dx
				ny = y + dy
				if 0 <= nx < cols and 0 <= ny < rows:
					fh = floors[y][x]
					ch = ceilings[y][x]
					fn = floors[ny][nx]
					cn = ceilings[ny][nx]
					if max(fh, fn) + 50 > cn:
						r = INFINITY
					elif fn + 50 > ch:
						r = INFINITY
					else:
						r = max(water - cn + 50, 0)
				else:
					r = INFINITY
				reachSquare.append(r)
			reachLine.append(reachSquare)
		reach.append(reachLine)

	start = (0, 0)
	exit = (cols - 1, rows - 1)

	newReached = start
	time = 0
	reachAt = {}
	reached = set()
	reachAtLast = []
	while newReached != exit:
		reached.add(newReached)
		x, y = newReached
		for (dx, dy), rt in zip(deltas, reach[y][x]):
			if rt < INFINITY:
				nx = x + dx
				ny = y + dy
				nxy = nx, ny
				if nxy not in reached:
					rt = max(time, rt)
					if rt > 0:
						wt = water - rt
						rt += 10 if wt >= floors[y][x] + 20 else 100
					best = reachAt.get(nxy, INFINITY)
					if rt < best:
						if best == INFINITY:
							oi = None
						else:
							oi = search(0, len(reachAtLast),
									lambda i: reachAt[reachAtLast[i]] <= best)
							while reachAtLast[oi] != nxy:
								oi += 1
								assert reachAt[reachAtLast[oi]] == best
						ni = search(0, len(reachAtLast),
								lambda i: reachAt[reachAtLast[i]] <= rt)
						if ni != oi:
							assert ni > oi
							reachAtLast.insert(ni, nxy)
							if oi is not None:
								del reachAtLast[oi]
						reachAt[nxy] = rt
						assert len(reachAtLast) == len(reachAt)
		newReached = reachAtLast[-1]
		del reachAtLast[-1]
		time = reachAt[newReached]
		del reachAt[newReached]

	return '%0.1f' % (time * 0.1)

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
		out.write('Case #%d: %s\n' % (case + 1, value))
		out.flush()
	out.close()
