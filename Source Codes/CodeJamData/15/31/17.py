def solve(test):
	r, c, w = map(int, input().split())

	ans = (c / w + w - 1) if c % w == 0 else (c / w + w)
	ans += (r - 1) * c / w
	print("Case #%d: %d" % (test, ans))


t = int(input())
for i in range(t):
 	solve(i + 1);
