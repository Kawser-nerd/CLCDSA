n,a,b = map(int,input().split())
n -= (a+b)*(n//(a+b))
if n == 0:
	print("Bug")
else:
	n -= a
	if n > 0:
		print("Bug")
	else:
		print("Ant")