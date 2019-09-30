T = input()
for i in xrange(T):
	C, D = map(int, raw_input().split())
	PV = [map(int, raw_input().split()) for j in xrange(C)]
	PV.sort()
	N = sum(pv[1] for pv in PV)
	pos = sum(([pv[0]] * pv[1] for pv in PV), [-10**10]) + [10**10]
	left, right = [0] * (N+2), [0] * (N+2)
	for j in xrange(2, N+1):
		left[j] = max(0, left[j-1] + D - pos[j] + pos[j-1])
	for j in xrange(N-1, 0, -1):
		right[j] = max(0, right[j+1] + D - pos[j+1] + pos[j])
	print 'Case #%d: %.1f' % (i+1, max(min(left[j], right[j]) + abs(left[j] - right[j])*.5 for j in xrange(1, N+1)))