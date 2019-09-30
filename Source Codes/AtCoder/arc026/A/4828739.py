n,a,b = map(int,input().split())
if n <= 5:
	print(n*b)
else:
	print(5*b+a*(n-5))