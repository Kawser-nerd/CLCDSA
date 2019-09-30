N, M = map(int, input().split())
B = []
for i in range(N):
	B.append([int(i) for i in input()])

A = [[0]*M for i in range(N)]
for i in range(1,N-1):
	for j in range(1,M-1):
		A[i][j] +=B[i-1][j]
		B[i][j-1] -= B[i-1][j]
		B[i][j+1] -= B[i-1][j]
		B[i+1][j] -= B[i-1][j]
		B[i-1][j] = 0

print(*("".join(map(str, l)) for l in A), sep="\n")