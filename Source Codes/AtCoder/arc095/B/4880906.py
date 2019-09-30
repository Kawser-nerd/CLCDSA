def getlist():
	return list(map(int, input().split()))

n = int(input())
a = getlist()
a = sorted(a)
x = a[-1]
xx = x / 2
y = 0
s = float("inf")
for i in range(n - 1):
	if abs(xx - a[i]) < s:
		s = abs(xx - a[i])
		y = a[i]

print(x, y)