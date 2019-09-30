N= int(input())
bit = bin(N)[2:]
k = len(bit)
dp = [[0] * 2 for i in range(len(bit) + 1)]
dp[0][0] = 1
dp[0][1] = 1
for i in range(k):
	j = int(bit[k-i-1])
	a,b,c = [(1,0,0),(1,1,0)][j]
	d,e,f = [(1, 1, 1),(0, 1, 2)][j]
	dp[i+1][0] = (a * dp[i][0] + b * dp[i][1] + c * 3**i) % 1000000007
	dp[i+1][1] = d * dp[i][0] + e * dp[i][1] + f * 3**i % 1000000007

print(dp[k][0])