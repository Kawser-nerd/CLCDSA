testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	n = int(raw_input())
	l = [int (x) for x in raw_input().split(" ")]
	p = [int (x) for x in raw_input().split(" ")]
	a = []
	for i in range(n):
		a += [[i, 1.0 * p[i] / l[i], l[i]]]
	a.sort(key = lambda x:-x[1])
	for i in a:
		ans += str(i[0]) + " "
	print (ans )
