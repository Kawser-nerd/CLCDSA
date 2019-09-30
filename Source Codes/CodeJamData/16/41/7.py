def solve(X, n):
	if count[X] == -1:
		return False
	if n == 0:
		return X
	if count[beats[X]]:
		count[beats[X]] -= 1
		x, y = solve(X, n - 1), solve(beats[X], n - 1)
		if x and y:
			if x > y:
				return y + x
			else:
				return x + y
	return False


for case in xrange(1, input() + 1):
	ans = 0
	N, R, P, S = map(int, raw_input().split())
	beats = {'P': 'R', 'R': 'S', 'S': 'P'}
	count = {'P': P - 1, 'R': R, 'S': S}
	A = solve('P', N)
	count = {'P': P, 'R': R - 1, 'S': S}
	B = solve('R', N)
	count = {'P': P, 'R': R, 'S': S - 1}
	C = solve('S', N)
	print "Case #" + str(case) + ":",
	if A or B or C:
		print min([x for x in [A, B, C] if x])
	else:
		print "IMPOSSIBLE"
