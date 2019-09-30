k = int(input())
if k == 1:
	print(1)
	print(1)
else:
	n = (k+3) // 4 * 2
	ans = [[0 for _ in range(n)] for _ in range(n)]
	for i in range(n):
		for j in range(n):
			if i % 2 == 0:
				ans[i][j] = (i+j) % n + 1
			else:
				if (i+j) % n + n+1 > k:
					ans[i][j] = (i+j) % n + 1
				else:
					ans[i][j] = (i+j) % n + n+1
	print(n)
	for i in range(n):
		print(*ans[i])