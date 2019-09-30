n = int(input())
c = list(input())
i = 0
n = 0
s = 0
y = 0
for char in c:
	if char == '1':
		i = i + 1
	elif char == '2':
		n = n + 1
	elif char == '3':
		s = s + 1
	elif char == '4':
		y = y + 1
print(max([i, n, s, y]), min([i, n, s, y]))