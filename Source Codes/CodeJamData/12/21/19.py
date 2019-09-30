def testCase():
	data = [int(v) for v in raw_input().split()]
	assert len(data) == data[0] + 1
	points = data[1:]
	X = sum(points)
	N = len(points)

	total = 2*X
	soll = total / float(N)
	result = [None] * N
	flag = True
	#print result, total, N, soll
	while flag:
		flag = False
		for i, p in enumerate(points):
			if result[i] is None and p >= soll:
				result[i] = 0
				N -= 1
				total -= p
				soll = total / float(N)
				flag = True
				#print result, total, N, soll
	for i, p in enumerate(points):
		if result[i] is None:
			result[i] = (total / float(N) - p) / X * 100

	#result = [max(0, (2*X / float(N) - s) / X * 100) for s in points]
	return " ".join("%.7f" % m for m in result)

if __name__ == '__main__':
	n = int(raw_input())
	for i in xrange(n):
		print "Case #%d: %s" % (i+1, testCase())
