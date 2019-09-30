T = int(raw_input())
for case in range(T):
	D, I, M, N = map(int, raw_input().split())
	a = map(int, raw_input().split())
	
	dp = [[0 for j in range(256)] for i in range(N+1)]
	for i in range(1, N+1):
		for j in range(256):
			#make 1..i smooth, with an end value of j
			#options
			# - delete the end value, and leave it up to the previous
			dp[i][j] = D + dp[i-1][j]
			# - modify
			for k in range(256):
				if abs(k-j) <= M:
					dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(a[i-1]-j))
		# alternatively you can insert stuff
		if M != 0:
			for j in range(256):
				for k in range(j):
					cost = (j-k+M-1)/M * I
					dp[i][j] = min(dp[i][j], dp[i][k] + cost)
		
			for j in range(255, -1, -1):
				for k in range(255, j, -1):
					cost = (k-j+M-1)/M * I
					dp[i][j] = min(dp[i][j], dp[i][k] + cost)
	
	ans = 1e9			
	for j in range(256):
		ans = min(ans, dp[N][j])
	print "Case #%d: %d" % (case+1, ans)