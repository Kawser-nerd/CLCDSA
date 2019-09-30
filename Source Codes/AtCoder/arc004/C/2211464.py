from fractions import Fraction

X = Fraction(input())

f = False
for i in range(2):
	N = int(2*X) + i
	M = N * (N + 1) // 2 - X * N
	if M == int(M) and 1 <= M <= N:
		print(N,M)
		f = True

if not f:
	print("Impossible")