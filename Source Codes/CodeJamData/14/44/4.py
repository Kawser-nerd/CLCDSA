from collections import Counter
get = lambda: map(int, raw_input().split())

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache:
			cache[args] = f(*args)
		return cache[args]
	return wrap

@memo
def fact(n):
	if n == 0: return 1
	return fact(n-1) * n

@memo
def nodeCount(s):
	return len(set(x[:i] for x in s for i in range(len(x)+1)))

@memo
def splits(s, n):
	if not s:
		return [tuple(tuple() for i in range(n))]
	if n == 1:
		return [(tuple(s),)]
	results = []
	for i in range(1 << len(s)):
		items = []
		oitems = []
		for j, item in enumerate(s):
			if (i >> j) & 1:
				items.append(item)
			else:
				oitems.append(item)
		for res in splits(tuple(oitems), n-1):
			results.append((tuple(items),) + res)
	return results


T, = get()

for testCase in range(1, T+1):
	M, N = get()
	poss = splits(tuple(raw_input().strip() for i in range(M)), N)
	counts = dict()
	for row in poss:
		count = sum(map(nodeCount, row))
		if count not in counts:
			counts[count] = 0
		counts[count] += 1
	result = max(counts.items())
	print 'Case #%d: %d %d' % (testCase, result[0], result[1])