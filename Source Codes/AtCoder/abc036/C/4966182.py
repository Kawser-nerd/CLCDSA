N=int(input())
A=[int(input()) for _ in range(N)]

def func(list:A)->list:
	m={b:i for i, b in enumerate(sorted(set(A)))}
	return [m[a] for a in A]

B=func(A)
for i in range(N):
	print(B[i])