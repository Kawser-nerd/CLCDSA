fp_r = open('b.in', 'r')
fp_w = open('b.out', 'w')
t = int(fp_r.readline())

memo = []
for i in range(0, 101, 1):
	memo.append([987654321 for j in range(256)])

for i in range(0, t, 1):
	data = fp_r.readline()
	arr = data.split()	

	c1 = int(arr[0])
	c2 = int(arr[1])
	m = int(arr[2])
	n = int(arr[3])

	data = fp_r.readline()
	arr = data.split()

	for j in range(0, n + 1, 1):
		for k in range(0, 256, 1):
			memo[j][k] = 987654321

	for j in range(0, 256, 1):
		memo[0][j] = 0

	for j in range(0, n, 1):		
		for k in range(0, 256, 1):

			value = memo[j][k] + c1
			memo[j+1][k] = min(memo[j+1][k], value)
			
			for l in range(0, 256, 1):
				if abs(k - l) <= m:
					value = memo[j][l] + abs(k - int(arr[j]))
					memo[j+1][k] = min(memo[j+1][k], value)


		if m != 0:
			temp = memo[j+1][:]
			for k in range(0, 256, 1):
				for l in range(0, 256, 1):
					ins = max(1, (abs(k - l) + m - 1) / m)
					temp[k] = min(temp[k], memo[j+1][l] + c2 * ins)

			for k in range(0, 256, 1):
				memo[j+1][k] = min(memo[j+1][k], temp[k])

	ret = 987654321
	for j in range(0, 256, 1):
		ret = min(ret, memo[n][j])

	fp_w.write("Case #" + str(i+1)+ ": " + str(ret) + "\n")
	