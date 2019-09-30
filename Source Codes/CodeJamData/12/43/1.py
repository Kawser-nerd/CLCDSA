testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	n = int(raw_input())
	see = [int(x)-1 for x in raw_input().split(" ")]
	m = [n-1] * n
	cm = 0
	for i in range(n-1):
		if i >= m[cm]:
			cm -= 1
		if see[i] > m[cm]:
			ans += "Impossible"
			break
		if see[i] < m[cm]:
			cm += 1
			m[cm] = see[i]
			
	else:
		height = [0] * n
		count = [-1] * n
		for i in see:
			count[i] += 1
		angle = [0] * n	
		for i in range(n-2,-1,-1):
			angle[i] = count[see[i]] + angle[see[i]]
			count[see[i]] -= 1
			height[i] = (see[i] - i) * angle[i] + height[see[i]]
		m = max(height)
		for i in height:
			ans += str(m-i) + " "
	print (ans)
