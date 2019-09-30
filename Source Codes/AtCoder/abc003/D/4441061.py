from math import factorial
R, C = map(int, input().split())
X, Y = map(int, input().split())
D, L = map(int, input().split())
den = factorial(D) * factorial(L)
def pattern(n):
	if n < D + L:
		return 0
	return factorial(n) // (den * factorial(n - D - L))
gorioshi0 = pattern(X * Y)
gorioshi1 = 2 * pattern((X - 1) * Y) + 2 * pattern(X * (Y - 1))
gorioshi2 = 4 * pattern((X - 1) * (Y - 1))
gorioshi3 = 0
gorioshi4 = 0
if X >= 2:
	gorioshi2 += pattern((X - 2) * Y)
	gorioshi3 += 2 * pattern((X - 2) * (Y - 1))
	if Y >= 2:
		gorioshi4 += pattern((X - 2) * (Y - 2))
if Y >= 2:
	gorioshi2 += pattern(X * (Y - 2))
	gorioshi3 += 2 * pattern((X - 1) * (Y - 2))
print((((R + 1 - X) * (C + 1 - Y)) * (gorioshi0 - gorioshi1 + gorioshi2 - gorioshi3 + gorioshi4)) % 1000000007)