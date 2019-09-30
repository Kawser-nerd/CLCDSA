N, Q = map(int, input().split())
R = [0 for _ in range(N)]
L = [0 for _ in range(N)]
for _ in range(Q):
	r,l = map(int, input().split())
	R[r-1] += 1
	L[l-1] += 1
now = 0
for n in range(N):
	now += R[n]
	print(now % 2, end = '')
	now -= L[n]
print()