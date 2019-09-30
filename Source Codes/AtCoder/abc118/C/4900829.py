def gcd(a, b):
	while b:
		a, b = b, a % b
	return a

N = int(input())
A = [int(i) for i in input().split()]
g = A[0]
for n in range(1,N):
    g = gcd(g,A[n])

print(g)