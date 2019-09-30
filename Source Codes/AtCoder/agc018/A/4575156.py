N, K = list(map(int, input().split()))
A = list(map(int, input().split()))

if N == 1:
	x = A[0]
else:
	a = A[0]
	for i in range(N - 1):
		b = A[i + 1]
		a, b = sorted([a, b])
		while True:
			if b % a == 0:
				break
			else:
				a, b = b % a, a
	x = a

if K % x == 0 and max(A) >= K:
	print("POSSIBLE")
else:
	print("IMPOSSIBLE")