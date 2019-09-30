a, b = eval("int(input())," * 2)
if a % b == 0:
  	print(0)
else:
	print(b - (a % b))