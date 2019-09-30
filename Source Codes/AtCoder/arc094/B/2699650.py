from math import sqrt

def func(a, b):
	if a == b:
		return (a - 1) * 2
	else:
		sq = int(sqrt(a * b))
		if a * b == sq ** 2:
			return (sq - 1) * 2 - 1
		elif sq * (sq + 1) > a * b:
			return (sq - 1) * 2
		elif sq * (sq + 1) == a * b:
			if abs(a - b) == 1:
				return (sq - 1) * 2
			else:
				return (sq - 1) * 2
		else:
			return sq * 2 - 1

q = int(input())
for _ in range(q):
	a, b = map(int, input().split())
	print(func(a, b))