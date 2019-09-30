a, b = map(int, input().split())
if a == b:
	print('Draw')
elif a>b:
	print(['Alice','Bob'][b==1])
else:
	print(['Bob','Alice'][a==1])