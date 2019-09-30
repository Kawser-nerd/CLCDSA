N = int(input())
A = list(map(int, input().split()))
ans = 0
k = True

while k:
	for i in range(len(A)):
		if A[i] % 2 == 1:
			k = False
			break

	if k:
		ans += 1
		for i in range(len(A)):
			A[i] = A[i] / 2

print(ans)