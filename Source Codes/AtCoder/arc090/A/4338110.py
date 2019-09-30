import numpy as np
N = int(input())
A1 = list(map(int, input().split()))
A2 = list(map(int, input().split()))
dp = np.zeros(N, dtype=int)
ans = 0
if N == 1:
	print(A1[0] + A2[0])
else:
	for i in range(N):
		if np.sum(A1[:i]) + np.sum(A2[i-1:]) > ans:
			ans = np.sum(A1[:i]) + np.sum(A2[i-1:])
	print(int(ans))