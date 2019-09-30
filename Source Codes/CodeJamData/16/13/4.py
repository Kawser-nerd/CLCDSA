import sys
inp = sys.stdin.readlines()

cases = int(inp.pop(0))

for case in range(1, cases + 1):
	N = int(inp.pop(0))
	bffs = map(lambda x: x - 1, map(int, inp.pop(0).split()))

	max_end = [0] * N
	max_cycle = 0

	for curr in range(N):
		visited = [0] * N
		step = 1
		prev = None
		while True:
			if bffs[bffs[curr]] == curr:
				max_end[curr] = max(max_end[curr], step)
				max_end[bffs[curr]] = max(1, max_end[bffs[curr]])
				break
			if visited[curr]:
				max_cycle = max(max_cycle, step - visited[curr])
				break
			visited[curr] = step
			prev = curr
			curr = bffs[curr]
			step += 1

	result = max(sum(max_end), max_cycle)
	print 'Case #{}: {}'.format(case, result)
