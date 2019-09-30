from collections import deque

H, W = map(int, input().split())
maze = [input() for i in range(H)]
reached = [[0] * W for i in range(H)]
score = -1
count = 0

for i in range(H):
    count += maze[i].count('#')

que = deque([])
que.append([0, 0])

flag = False
while que:
    py, px = que.popleft()
    dy = (0, 1, 0, -1)
    dx = (1, 0, -1, 0)
    for j, i in zip(dy, dx):
        ny = py + j
        nx = px + i
        if ny < 0 or ny >= H or nx < 0 or nx >= W:
            continue
        if maze[ny][nx] == '#':
            continue
        if reached[ny][nx]:
            continue

        que.append([ny, nx])
        reached[ny][nx] += reached[py][px] + 1
        if ny == H-1 and nx == W-1:
            score = reached[ny][nx]
            flag = True
            break
    if flag:
        break

if flag:
    score = H * W - score - count - 1
    print(score)
else:
    print(score)