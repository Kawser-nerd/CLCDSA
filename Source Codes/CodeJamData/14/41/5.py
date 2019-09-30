cases = int(raw_input())

for tc in xrange(cases):
	n, m = tuple([int(i) for i in raw_input().split()])
	size = [int(i) for i in raw_input().split()]
	size.sort()
	res = 0
	while 2 <= len(size):
		if size[0] + size[-1] <= m:
			size = size[1:-1]
		else:
			size = size[:-1]
		res += 1
	if len(size):
		res += 1
	print 'Case #%d: %d' % (tc + 1, res)