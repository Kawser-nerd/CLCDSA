from __future__ import division
import bisect

T = int(raw_input())

for test in xrange(T):
	N = int(raw_input())
	trees = []
	for i in xrange(N):
		x, y = map(int, raw_input().split())
		trees.append((x, y))
	print "Case #{}:".format(test + 1)
	for x0, y0 in trees:
		left = []
		right = []
		up = 0
		down = 0
		for x1, y1 in trees:
			x = x1 - x0
			y = y1 - y0
			if x > 0:
				right.append(y / x)
			elif x < 0:
				left.append(y / x)
			elif y > 0:
				up += 1
			elif y < 0:
				down += 1
		left.sort()
		right.sort()
		ans = min(len(left), len(right))
		for i, angle in enumerate(left):
			cut_after = down + len(left) - 1 - i + bisect.bisect_left(right, angle)
			cut_before = up + i + len(right) - bisect.bisect_right(right, angle)
			cut = min(cut_after, cut_before)
			ans = min(ans, cut)
		print ans
