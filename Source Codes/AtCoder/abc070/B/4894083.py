a, b, c, d = map(int, input().split())


if a < c :
	x = c
else:
	x = a

if b < d :
	y = b
else:
	y = d

print(max(0,y - x))