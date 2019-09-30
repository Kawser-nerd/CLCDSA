f = lambda x: sum(map(int, str(x)))

a, b = 1, 1
for i in range(int(input())):
	print(a)
	a += 1
	b = a
	for j in range(0, len(str(a)) + 1):
		t = a % 10 ** j
		t = a - t + 10 ** j - 1
		if b * f(t) > t * f(b):
			b = t
	a = b