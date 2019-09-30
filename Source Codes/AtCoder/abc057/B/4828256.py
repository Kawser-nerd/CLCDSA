N, M = map(int, input().split())
STUDENTS = [tuple(map(int, input().split())) for _ in range(N)]
CHECKPOINTS = [tuple(map(int, input().split())) for _ in range(M)]
for student in STUDENTS:
	L = 10 ** 10
	for i, checkpoint in enumerate(CHECKPOINTS):
		l = abs(checkpoint[0] - student[0]) + abs(checkpoint[1] - student[1])
		if l < L:
			nc = i + 1
			L = l
	print(nc)