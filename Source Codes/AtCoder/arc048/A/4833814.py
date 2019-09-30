a,b = map(int,input().split())
if a*b < 0:
	print(abs(a-b)-1)
else:
	print(abs(a-b))