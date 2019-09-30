def main():
	N = int(input())
	dp = [1]*(N+1)
	ans = 0
	for i in range(2, N+1):
		div = 1
		while i * div <= N:
			dp[i*div] += 1
			div += 1
		if dp[i] == 8 and i%2==1:
			ans += 1
	print(ans)

if __name__ == '__main__':
    main()