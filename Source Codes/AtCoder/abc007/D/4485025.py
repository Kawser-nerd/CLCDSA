whitedigits = [0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8]

def count(n, whitedigits=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]):
	n += 1
	c = 0
	d = 1
	while n > 0:
		digit = n % 10
		c *= whitedigits[digit+1] - whitedigits[digit]
		c += whitedigits[digit] * d
		d *= whitedigits[10]
		n //= 10
	return c

A, B = map(int, input().split())
print((B - count(B, whitedigits)) - (A-1 - count(A-1, whitedigits)))