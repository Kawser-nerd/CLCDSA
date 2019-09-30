t = int(input())

for test in range(0, t):
	a, n = [int(x) for x in input().split()]
	
	v = [int(x) for x in input().split()]
	
	v = sorted(v)

	ans = n
	for i in range(0, n + 1):
		t = i  
		b = a
		for j in range(0, n - i):
			while v[j] >= b:
				t = t + 1
				b = b + (b - 1)
				if (b == 1):
					t = n + 1
					break
			b = b + v[j]
		if t < ans:
			ans = t

	print("Case #" + str(test + 1) + ": " + str(ans))