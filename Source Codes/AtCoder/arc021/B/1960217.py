L = int(input())
B = [int(input()) for _ in range(L)]
A = [0] * L

for i in range(1,L):
	A[i] = B[i-1] ^ A[i-1]

if A[0] ^ A[L-1] != B[L-1]:
	print(-1)
else:
	print("\n".join(map(str,A)))