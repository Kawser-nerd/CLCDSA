N, A, B = list(map(int, input().split()))
s = 0
X = list(map(int, input().split()))

for i in range(1, N):
	s += min((X[i] - X[i - 1]) * A, B)

print(s)