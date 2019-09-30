testSum = input()
for test in xrange(testSum):
	x, y, w = map(int, raw_input().split())
	ans = x * ((y-1) / w + 1) + w - 1
	print "Case #" + str(test + 1) + ":", ans
