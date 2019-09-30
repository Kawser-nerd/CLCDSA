import sys
def dfs(x, y):
	global a
	f, g = [], 1
	for i in a[x]:
		if i != y:
			ff, gg = dfs(i, x)
			g += gg
			f.append(ff - gg)
	f = sorted(f)
	if len(f) >= 2:
		return g + f[0] + f[1] - 1, g
	else:
		return g - 1, g

t = input()
for tt in range(t):
	print >>sys.stderr, "???",tt
	n = input()
	a = [[] for i in range(n + 1)]
	for i in range(n - 1):
		x, y = map(int, raw_input().split())
		a[x].append(y)
		a[y].append(x)
	ans = n
	for i in range(1, n + 1):
		f, g = dfs(i, 0)
		if f == -1:
			f = g
		ans = min(ans, f)
	print "Case #%d:"%(tt + 1),
	print ans
