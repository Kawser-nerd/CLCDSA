def worst(n, i): # return worst-case rank (0 <= i < 2^n)
	if n == 0:
		return 0
	else:
		if i == 0: return 0
		else:
			return 2 ** (n - 1) + worst(n - 1, (i - 1) // 2)

def answer(N, P):
	l, r = -1, 2 ** N - 1
	while l != r:
		m = (l + r) >> 1
		if worst(N, m + 1) < P:
			l = m + 1
		else:
			r = m
	return l

T = int(raw_input())
for case_nr in range(1, T + 1):
	N, P = map(int, raw_input().split())
	ans1 = answer(N, P)
	ans2 = answer(N, 2**N - P)
	print "Case #%d: %d %d" % (case_nr, ans1, 2**N - ans2 - 2)
