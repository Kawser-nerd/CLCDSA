testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	n = int(raw_input())
	a = []
	for i in range(n):
		a1, a2 = [int(x) for x in raw_input().split(" ")]
		a += [(a1, a2, 2)]
	a.sort(key=lambda x:x[1]*10000+x[0])
	star = 0
	count = 0
	for i in range(n):
		need = a[i][1] - star
		while need > 0:
			flag = True
			for j in range(n-1, i-1, -1):
				if a[j][2] == 2 and star >= a[j][0]:
					a[j] = (a[j][0],a[j][1],1)
					need -= 1
					star += 1
					count += 1
					flag = False
					break
			if flag:
				break
		if need > 0:
			ans += "Too Bad"
			break
		
		star += a[i][2]
		count += 1
	if star == n * 2:
		ans += str(count)
	print (ans)
