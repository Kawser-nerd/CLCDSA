import sys
inp = sys.stdin.readlines()

cases = int(inp.pop(0))

for case in range(1, cases + 1):
	N = int(inp.pop(0))
	counts = dict()
	for r in range(2*N - 1):
		row = map(int, inp.pop(0).split())
		for i in row:
			if i not in counts:
				counts[i] = 0
			counts[i] += 1

	missing = []
	for key, val in counts.iteritems():
		if val % 2:
			missing.append(key)
	result = ' '.join(map(str, sorted(missing)))
	print 'Case #{}: {}'.format(case, result)
