from collections import deque
k = int(input())
dis = [float("inf") for _ in range(k)]

def bfs(start, goal):
	que = deque([[start, 1]])
	while que:
		label = que.pop()
		l, c = label[0], label[1]
		if l == goal:
			return c
		if dis[l] > c:
			dis[l] = c
			que.append([(l*10)%k, c])
			que.appendleft([(l+1)%k, c+1])

print(bfs(1, 0))