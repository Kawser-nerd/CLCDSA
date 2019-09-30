A, B, C, D = list(map(int, input().split()))

L = A+B
R = C+D
if L>R:
	print('Left')
elif L==R:
	print('Balanced')
elif L<R:
	print('Right')