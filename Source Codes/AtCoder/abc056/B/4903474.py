W, a, b = map(int, input().split())

if a+W < b:
	print(b-a-W)
elif b+W < a:
	print(a-b-W)
else:
	print(0)