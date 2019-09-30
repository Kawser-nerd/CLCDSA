h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
ys,xs=set(),set()
for y in range(h):
	for x in range(w):
		if a[y][x] == "#":
			ys.add(y)
			xs.add(x)
for y in sorted(list(ys)):
	for x in sorted(list(xs)):
		print(a[y][x], end="")
	print("")