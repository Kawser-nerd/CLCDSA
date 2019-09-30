from collections import deque
h, w = map(int, input().split())
board = [list(input()) for _ in range(h)]

for x in range(w):
    for y in range(h):
        if board[y][x] == "s":
            s = [y, x]
        if board[y][x] == "g":
            g = [y, x]
d = [[-1 for _ in range(w)] for _ in range(h)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
queue = deque([])
queue.append(s)
d[s[0]][s[1]] = 0
while len(queue) != 0:
    p = queue.popleft()
    for x, y in zip(dx, dy):
        nx = p[1] + x
        ny = p[0] + y
        if 0<=nx<w and 0<=ny<h and d[ny][nx] == -1:
            if board[ny][nx] == "#":
                d[ny][nx] = d[p[0]][p[1]] + 1
                queue.append([ny, nx])
            else:
                d[ny][nx] = d[p[0]][p[1]]
                queue.appendleft([ny, nx])
if d[g[0]][g[1]] <= 2:
    print("YES")
else:
    print("NO")