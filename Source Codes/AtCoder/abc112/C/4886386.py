n = int(input())
a = []
for i in range(n):
	a.append([int(n) for n in input().split()])
	a[i][0], a[i][2] = a[i][2], a[i][0]
a = sorted(a)
for x in range(101):
	for y in range(101):
		h = a[n - 1][0] + abs(x - a[n - 1][2]) + abs(y - a[n - 1][1])
		for k in range(n):
			d = h - abs(x - a[k][2]) - abs(y - a[k][1])
			if a[k][0] != max(d, 0):
				break
			if k == n - 1:
				print(x, y, h)
				exit()