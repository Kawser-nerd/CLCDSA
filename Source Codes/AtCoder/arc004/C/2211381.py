def gcd(x,y):
	return gcd(y, x % y) if y > 0 else x

X,Y = map(int,input().split('/'))

g = gcd(X,Y)
X = X // g
Y = Y // g
N = 0
M = 0
found = False
for i in range(1,5):
	N = int(int(2 * X / Y) - 1 + i)
	if N % Y > 0:
		continue

	si = N * (N + 1) // 2
	na = X * N // Y
	M = si - na
	if 1 <= M and M <= N:
		print(N,M)
		found = True

if found == False:
	print("Impossible")