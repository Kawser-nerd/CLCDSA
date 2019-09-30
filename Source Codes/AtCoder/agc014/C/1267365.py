import math
H,W,K = map(int,input().split())
HW = [list(input()) for i in range(H)]
for i,h in enumerate(HW):
	if "S" in h:
		y = i
		x = h.index("S")
A = [(x,y)]
m = 800
def idou(a,b):
	X = []
	for i2 in range(4):
		if i2 == 0:
			t,k = a - 1, b
		elif i2 == 1:
			t,k = a, b - 1
		elif i2 == 2:
			t,k = a + 1, b
		elif i2 == 3:
			t,k = a, b + 1
		if 0 <= t < W and 0 <= k < H and HW[k][t] == ".":
			HW[k][t] = "o"
			X.append((t,k))
	return X
cnt = 0
while cnt < K:
	cnt += 1
	B = []
	for p in A:
		x,y = p
		b = idou(x,y)
		B.extend(b)
	A = B[:]
M = []
for i,w in enumerate(zip(*HW)):
	#print(w)
	if "o" in w or "S" in w:
		M.append(min(i,W - i - 1))
		
for i,h in enumerate(HW):
	if "S" in h or "o" in h:
		M.append(min(i, H - i - 1))
		#print(h)
m = min(M)
print((m + K - 1) // K + 1)