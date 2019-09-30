get = lambda: map(int, raw_input().split())

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache: cache[args] = f(*args)
		return cache[args]
	return wrap

def solve():
	R, C = get()

	def getRows(c):
		if c == 0:
			yield []
		else:
			for row in getRows(c-1):
				yield row + [1]
				yield row + [2]
				yield row + [3]

	@memo
	def genRows(r):
		res = []
		for row in getRows(C):
			rem = list(row)
			for i in range(C-1):
				if row[i] == row[i+1]:
					rem[i] -= 1
					rem[i+1] -= 1
			if row[0] == row[-1]:
				rem[0] -= 1
				rem[-1] -= 1
			if all(x >= 0 for x in rem):
				res.append((tuple(row), tuple(rem)))
		return res

	#print R, C
	#print '\n'.join(map(repr, genRows(R)))
	#print

	def rot(current, i):
		return tuple(row[i:] + row[:i] for row in current)

	def minRot(current):
		return min(rot(current, i) for i in range(C))

	def DP(prevRow, prevRem, r, current):
		if r == 0:
			if all(x == 0 for x in prevRem):
				yield minRot(current)
		else:
			for row, rem in genRows(r):
				if all(prevRem[i] - (1 if prevRow[i] == row[i] else 0) == 0 for i in range(C)):
					current.append(row)
					for res in DP(row, tuple(rem[i] - (1 if prevRow[i] == row[i] else 0) for i in range(C)), r-1, current):
						yield res
					current.pop()

	return len(set(DP((0,)*C, (0,)*C, R, [])))


T, = get()

for testCase in range(1, T+1):
	print "Case #%d: %d" % (testCase, solve())