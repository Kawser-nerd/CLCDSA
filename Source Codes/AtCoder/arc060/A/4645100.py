N, A = list(map(int, input().split()))
x = list(map(int, input().split()))
for i in range(N):
	x[i] -= A

L = [[0 for i in range(10002)] for j in range(N)]
for i in range(N):
	L[i][5001 + x[i]] = 1

for i in range(N - 1):
	for j in range(10002):
		if L[i][j] != 0:
			L[i + 1][j] += L[i][j]
			L[i + 1][j + x[i + 1]] += L[i][j]

print(L[N - 1][5001])