def solve(test):
	c, n, v = map(int, input().split())

	a = map(int, input().split())
	a = sorted(a)

	ans = 0
	cur = 0
	for i in range(n):
		while cur < a[i] - 1:
			ans += 1
			cur += (cur + 1) * c
		cur += a[i] * c

	while cur < v:
		ans += 1
		cur += (cur + 1) * c

	print("Case #%d: %d" % (test, ans))


t = int(input())
for i in range(t):
 	solve(i + 1);
