N, M = map(int, input().split())
R = [tuple(map(int, input().split())) for _ in range(M)]
C = [[] for _ in range(N)]
for r in R:
	C[r[0]-1].append(r[1]-1)
	C[r[1]-1].append(r[0]-1)
for c in C:
	print(len(c))