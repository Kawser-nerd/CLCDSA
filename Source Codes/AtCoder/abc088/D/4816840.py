import queue

H, W = list(map(int, input().split()))
ans = H * W
L = []
for i in range(H):
	s = list(input())
	ans -= s.count("#")
	L.append(s)

length = [[float("inf") for i in range(W)] for j in range(H)]
length[0][0] = 0

def breadth(H, W, q, L, length, goal):
	while not q.empty():
		m = q.get()
		x = m[0]
		y = m[1]
		if [x, y] == goal:
			break

		if y - 1 >= 0:
			if length[y - 1][x] > length[y][x] + 1:
				if L[y - 1][x] == ".":
					length[y - 1][x] = length[y][x] + 1
					q.put([x, y - 1])
		if y + 1 <= H - 1:
			if length[y + 1][x] > length[y][x] + 1:
				if L[y + 1][x] == ".":
					length[y + 1][x] = length[y][x] + 1
					q.put([x, y + 1])
		if x - 1 >= 0:
			if length[y][x - 1] > length[y][x] + 1:
				if L[y][x - 1] == ".":
					length[y][x - 1] = length[y][x] + 1
					q.put([x - 1, y])
		if x + 1 <= W - 1:
			if length[y][x + 1] > length[y][x] + 1:
				if L[y][x + 1] == ".":
					length[y][x + 1] = length[y][x] + 1
					q.put([x + 1, y])
	return length[-1][-1]

q = queue.Queue()
q.put([0, 0])
goal = [W - 1, H - 1]
goal_len = breadth(H, W, q, L, length, goal)

if length[H - 1][W - 1] == float("inf"):
	print(-1)
else:
	print(ans - goal_len - 1)