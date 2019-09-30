A, K = list(map(int, input().split()))
if K == 0:
	print(2*10**12 - A)
else:
	cnt = 0
	while A < 2*10**12:
		cnt += 1
		A += A * K + 1
	print(int(cnt))