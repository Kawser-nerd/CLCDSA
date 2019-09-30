cmb = [[1]]
for i in range(1, 100 + 1):
	cmb.append([1] + [cmb[i - 1][j - 1] + cmb[i - 1][j] for j in range(1, i)] + [1])

cases = int(raw_input())

def comb(n, k):
	return cmb[n][k]

def calc(inp, idx, now):
	res = []
	if inp[idx] == now:
		res.append((1, 0, 1))
		idx += 1
	while idx < len(inp) and inp[idx].startswith(now):
		idx, tr = calc(inp, idx, inp[idx][:len(now) + 1])
		res.append(tr)
	listgroup = [group for group, count, cases in res]
	maxgroup = max(listgroup)
	sumgroup = min(sum(listgroup), m)
	listcount = [count for group, count, cases in res]
	sumcount = sum(listcount)

	sumcases = 0
	fc = 1
	for i in range(sumgroup, maxgroup - 1, -1):
		tc = comb(sumgroup, i)
		for group, count, cases in res:
			tc = (tc * comb(i, group)) % 1000000007
			tc = (tc * cases) % 1000000007
		sumcases += tc * fc
		while sumcases < 0:
			sumcases += 1000000007
		sumcases %= 1000000007
		fc *= -1

	sumcount += sumgroup

	return (idx, (sumgroup, sumcount, sumcases))

for tc in xrange(cases):
	n, m = tuple([int(i) for i in raw_input().split()])
	inp = []
	for i in xrange(n):
		inp.append(raw_input())
	inp.sort()
	idx, res = calc(inp, 0, '')
	group, count, cases = res
	print 'Case #%d: %d %d' % (tc + 1, count, cases)