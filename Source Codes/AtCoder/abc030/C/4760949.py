N, M = map(int, input().split())
X, Y = map(int, input().split())
A = list( map(int, input().split()) )
B = list( map(int, input().split()) )
case = 'A'
i = 0
a = 0
b = 0
ans = 0
while(1):
	if case == 'A':
		while i > A[a]:
			a += 1
			if a >= N:
				print(ans//2)
				exit()
		i = A[a] + X
		ans += 1
		case = 'B'
	if case == 'B':
		while i > B[b]:
			b += 1
			if b >= M:
				print(ans//2)
				exit()
		i = B[b] + Y
		ans += 1
		case = 'A'