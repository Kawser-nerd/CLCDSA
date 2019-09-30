n = int(input())
lis = []
for m in range(n):
	lis.append(list(map(int, input().split())))
mat = 0
for i, cou in enumerate(lis):
	for co in lis[i+1:]:
		ix, yx, cx = cou
		iy, yy, cy = co
		d = max(abs(ix - iy), abs(yx - yy))
		tim = (cx * cy * d / (cx + cy))
		mat = max(tim, mat)
print(mat)