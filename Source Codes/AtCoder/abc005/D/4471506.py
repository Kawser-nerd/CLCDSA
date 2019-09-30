import numpy as np

N = int(input())
D = np.zeros((N+1, N+1), dtype=np.int)
for i in range(N):
	for j, value in enumerate(map(int, input().split())):
		D[i+1, j+1] = value

np.cumsum(D[1:, 1:], axis=0, out=D[1:, 1:])
np.cumsum(D[1:, 1:], axis=1, out=D[1:, 1:])

maxs = np.zeros((N*N+1), dtype=D.dtype)
for r in range(1, N+1):
	for c in range(1, N+1):
		maxs[r * c] = max(maxs[r * c], max(
			D[i+r, j+c] - D[i, j+c] - D[i+r, j] + D[i, j]
			for i in range(N-r+1)
			for j in range(N-c+1)
		))

for p in range(1, N*N+1):
	maxs[p] = max(maxs[p], maxs[p-1])

Q = int(input())
for q in range(Q):
	P = int(input())
	print(maxs[P])