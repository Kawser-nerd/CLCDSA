s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for case in xrange(1, input() + 1):
	n = input()
	cnt = map(int, raw_input().split())
	print "Case #" + str(case) + ":",
	while sum(cnt):
		x, y = sorted([(x, i) for i, x in enumerate(cnt)])[-2:]
		if sum(cnt) % 2 == 0:
			print s[x[1]] + s[y[1]],
			cnt[x[1]] -= 1
			cnt[y[1]] -= 1
		else:
			print s[y[1]],
			cnt[y[1]] -= 1
	print
