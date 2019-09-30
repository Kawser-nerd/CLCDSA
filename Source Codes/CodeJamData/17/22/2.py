t = input()
def fuck(A, a, B, b, C, c):
	if a < b:
		return fuck(B, b, A, a, C, c)
	if b < c:
		return fuck(A, a, C, c, B, b)
	d = b + c - a
	assert d >= 0
	b -= d
	c -= d
	return (A + B) * b + (A + B + C) * d + (A + C) * c
def solve(n, r, o, y, g, b, v):
	if o == b and o + b == n:
		return 'OB' * b
	if g == r and g + r == n:
		return 'GR' * g
	if v == y and v + y == n:
		return 'VY' * v
	if o > 0 and o >= b or g > 0 and g >= r or v > 0 and v >= y:
		return 'IMPOSSIBLE'
	b -= o
	r -= g
	y -= v
	s = b + r + y
	if 2 * b > s or 2 * r > s or 2 * y > s:
		return 'IMPOSSIBLE'
	z = fuck('B', b, 'R', r, 'Y', y)
	for i in range(len(z)):
		if z[i] == 'B':
			z = z[:i] + 'BO' * o + z[i:]
			break
	for i in range(len(z)):
		if z[i] == 'R':
			z = z[:i] + 'RG' * g + z[i:]
			break
	for i in range(len(z)):
		if z[i] == 'Y':
			z = z[:i] + 'YV' * v + z[i:]
			break
	return z
for tt in range(1, t + 1):
	n, r, o, y, g, b, v = map(int, raw_input().split())
	cao = solve(n, r, o, y, g, b, v)
	if cao != 'IMPOSSIBLE':
		assert len(cao) == n
		assert cao.count('R') == r
		assert cao.count('B') == b
		assert cao.count('Y') == y
	print 'Case #%d: %s' % (tt, cao)