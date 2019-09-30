H,W=[int(i) for i in input().split()]
a=[input() for i in range(H)]

R = [[False for i in range(W)] for j in range(H)]
B = [[False for i in range(W)] for j in range(H)]

#???
for i in range(H):
	R[i][0] = B[i][-1] = True
	if i%2 == 0:
		for j in range(1,W-1):
			R[i][j] = True
	else:
		for j in range(1,W-1):
			B[i][j] = True

#????
for i in range(H):
	for j in range(W):
		if a[i][j] == '#':
			R[i][j] = B[i][j] = True

#??
for row in R:
	for col in row:
		print('#' if col else '.',end="")
	print()
print()
for row in B:
	for col in row:
		print('#' if col else '.',end="")
	print()