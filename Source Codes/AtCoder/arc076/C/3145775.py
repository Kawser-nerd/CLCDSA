r, c, n = map(int, input().split())
dots = []
num = 0
for i in range(n):
	x1, y1, x2, y2 = map(int, input().split())
	if (0 < x1 < r and 0 < y1 < c) or (0 < x2 < r and 0 < y2 < c):
		continue
	else:
		num += 1
		d1 = (x1, y1)
		d2 = (x2, y2)
		if x1 == 0:
			dots.append((y1, i))
		elif y1 == c:
			dots.append((c + x1, i))
		elif x1 == r:
			dots.append((2 * c + r - y1, i))
		else:
			dots.append((2 * (r + c) - x1, i))

		if x2 == 0:
			dots.append((y2, i))
		elif y2 == c:
			dots.append((c + x2, i))
		elif x2 == r:
			dots.append((2 * c + r - y2, i))
		else:
			dots.append((2 * (r + c) - x2, i))

#print(dots)
if num <= 1:
	print("YES")
else:
	dots.sort(key=lambda x: x[0])
	stack = []
	for i in range(num * 2):
		if stack == []:
			stack.append(dots[i][1])
		else:
			if stack[-1] == dots[i][1]:
				stack.pop()
			else:
				stack.append(dots[i][1])
	if stack:
		print("NO")
	else:
		print("YES")