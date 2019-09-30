from collections import deque
H, W, K = map(int, input().split())
m = [input() for i in range(H)]
v = [[0]*W for i in range(H)]
f = 0
for i in range(H):
	if f:
		break
	for j in range(W):
		if m[i][j] == "S":
			x = i
			y = j
			f = 1
			break
dq = deque([[x,y,0]])
v[x][y] = 1
ans = (min(x, y, H-1-x, W-1-y)+K-1)//K
while dq:
	x, y, c = dq.popleft()
	ans = min(ans, (min(x, y, H-1-x, W-1-y)+K-1)//K)
	if c < K:
		c += 1
		if x > 0 and m[x-1][y] == "." and not v[x-1][y]:
			dq.append([x-1,y,c])
			v[x-1][y] = 1
		if x < H-1 and m[x+1][y] == "." and not v[x+1][y]:
			dq.append([x+1,y,c])
			v[x+1][y] = 1
		if y > 0 and m[x][y-1] == "." and not v[x][y-1]:
			dq.append([x,y-1,c])
			v[x][y-1] = 1
		if y < W-1 and m[x][y+1] == "." and not v[x][y+1]:
			dq.append([x,y+1,c])
			v[x][y+1] = 1
print(ans+1)