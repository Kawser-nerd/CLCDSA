whitedigits = [0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8]

def count(n, whitedigits=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]):
	c = 0
	flow = 1
	for digit in map(int, str(n+1)):
		c *= whitedigits[10]
		c += whitedigits[digit] * flow
		flow = (whitedigits[digit+1] - whitedigits[digit]) * flow
	# print(f'{n}: {c} / {n+1} - {n+1-c}')
	return c

A, B = map(int, input().split())
print((B - count(B, whitedigits)) - (A-1 - count(A-1, whitedigits)))