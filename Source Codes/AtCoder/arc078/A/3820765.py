N = int(input())
a = list(map(int, input().split()))

ans = float("inf")
X = a[0]
Y = sum(a) - a[0]

for i in range(1, N):
	if abs(X - Y) < ans:
		ans = abs(X - Y)

	X += a[i]
	Y -= a[i]

print(ans)