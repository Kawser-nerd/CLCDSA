import math
N, Q = map(int,input().split())
X = [0] * N
R = [0] * N
H = [0] * N
for i in range(N):
	X[i], R[i], H[i] = map(int,input().split())
A = [0] * Q
B = [0] * Q
for i in range(Q):
	A[i], B[i] = map(int,input().split())

MAX_X = 3*10**4
V = [0] * MAX_X # [x,x+1](0 ? x < 3*10**4) ?????
for x in range(MAX_X):
	for i in range(N):
		if X[i] > x or X[i] + H[i] < x:
			continue
		else:
			Rleft  = (X[i] + H[i] - x) * R[i] / H[i]
			Rright = max(0,(X[i] + H[i] - (x + 1)) * R[i] / H[i])
			Vleft  = math.pi * Rleft ** 2 * (X[i] + H[i] - x) / 3
			Vright = math.pi * Rright ** 2 * (X[i] + H[i] - (x+1)) / 3
			V[x]  += Vleft - Vright

cum_sum = [0] * (MAX_X + 1)
for x in range(MAX_X):
	cum_sum[x+1] = V[x] + cum_sum[x]

for i in range(Q):
	res = cum_sum[B[i]] - cum_sum[A[i]]
	print(res)