cases = int(raw_input())

for tc in xrange(cases):
	n = int(raw_input())
	num = [int(i) for i in raw_input().split()]
	res = 0
	while len(num):
		i = num.index(min(num))
		res += min(i, len(num) - i - 1)
		num = num[:i] + num[i + 1:]
	print 'Case #%d: %d' % (tc + 1, res)