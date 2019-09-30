testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	n = int(raw_input())
	v = []
	for i in range(n):
		v += [[int(x) for x in raw_input().split(" ")]]
	g = int(raw_input())
	
	p = [0] * n
	p[0] = v[0][0]
	res = False
	for i in range(n):
		if p[i] + v[i][0] >= g:
			res = True
			break
		for j in range(i+1,n):
			if p[i] + v[i][0] < v[j][0]:
				break
			else:
				pp = min(v[j][1], v[j][0]-v[i][0])
				p[j] = max(p[j], pp) 
	if res:
		ans += "YES"
	else:
		ans += "NO"
	print (ans)
