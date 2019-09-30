T = int(raw_input())
for kase in range(1, T + 1):
	n, m, c = map(int, raw_input().split())
	ans = n * (m / c)
	if m % c == 0:
		ans += c - 1
	else:
		ans += c
	
	print "Case #" + str(kase) + ": " + str(ans)
