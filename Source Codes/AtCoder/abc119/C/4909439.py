N, A, B, C = map(int, input().split())
l = []
for i in range(N):
	l.append(int(input()))
X = []
for i in range(4 ** N):
	num = []
	for j in range(N):
		num.append(i % 4)
		i //= 4
	a, b, c, x = 0, 0, 0, -30
	for k in range(N):
		if num[k] == 0:
			a += l[k]
			x += 10
		elif num[k] == 1:
			b += l[k]
			x += 10
		elif num[k] == 2:
			c += l[k]
			x += 10
	if a * b * c != 0:
		x += abs(A - a) + abs(B - b) + abs(C - c)
		X.append(x)
print(min(X))