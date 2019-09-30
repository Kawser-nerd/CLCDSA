def main():
	N, M, Q = map(int, input().split())
	LR = [[0 for _ in range(N+1)] for _ in range(N+1)]
	ans = [0]*Q
	for _ in range(M):
		l, r = map(int, input().split())
		LR[l][r] += 1
	for i in range(1, N+1):
		for j in range(1, N+1):
			LR[i][j] += LR[i][j-1]
	for i in range(1, N+1):
		for j in range(1, N+1):
			LR[i][j] += LR[i-1][j]

	for i in range(Q):
		p, q = map(int, input().split())
		ans[i] = LR[q][q] + LR[p-1][p-1] - LR[p-1][q] - LR[q][p-1]
	for a in ans:
		print(a)


if __name__ == '__main__':
    main()