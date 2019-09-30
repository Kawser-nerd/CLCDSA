testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	n,m = [int(x) for x in raw_input().split(" ")]
	p = [float(x) for x in raw_input().split(" ")]
	minType = m + 1.0
	p1 = reduce(lambda x,y:x*y, p, 1.0)
	type = (m-n) * p1 + (m-n + 1 + m) * (1-p1)
	minType = min(type, minType)
	p1 = 1.0
	for i in range(1,n):
		p1 *= p[i-1]	
		type = (n-i + m-i) * p1 + (n-i + m-i + 1 + m) * (1-p1)
		minType = min(type, minType)
	print (ans + str(minType + 1.0))
