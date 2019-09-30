def main():
	N = int(input())
	dp = [False]*(101)
	dp[0] = True
	dp[4] = True
	dp[7] = True
	for i in range(4, 101):
		if i + 7 <= 100:
			dp[i+7] = dp[i+7] or dp[i]
		if i + 4 <= 100:
			dp[i+4] = dp[i+4] or dp[i]

	if dp[N]:
		print("Yes")
	else:
		print("No")

if __name__ == '__main__':
    main()