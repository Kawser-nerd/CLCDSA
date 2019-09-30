n = int(input())
b = [int(input()) for i in range(n)]
xor = b[0]
for i in b[1:n-1]: xor = xor^i
if b[-1]!=xor: print(-1)
else:
	a = 0
	for i in range(n):
		print(a)
		a = a^b[i]