from collections import deque

def bfs():
    d = [[[False] * 3 for j in range(w)] for i in range(h)]

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    for i in range(h):
        for j in range(w):
            if maze[i][j] == "s":
                sx = i
                sy = j
            if maze[i][j] == "g":
                gx = i
                gy = j

    que = deque([])
    que.append((sx, sy, 0))
    d[sx][sy][0] = True

    while que:
        p = que.pop()
        if p[0] == gx and p[1] == gy:
            break
        for i in range(4):
            nx = p[0] + dx[i]
            ny = p[1] + dy[i]
            t = p[2]

            if not (0 <= nx and nx < h and 0 <= ny and ny < w):
                continue
            if t == 2 and maze[nx][ny] == "#":
                continue
            if d[nx][ny][t]:
                continue
            if maze[nx][ny] == "#":
                que.append((nx, ny, t + 1))
                d[nx][ny][t + 1] = True
            else:
                que.append((nx, ny, t))
                d[nx][ny][t] = True

    for i in range(3):
        if d[gx][gy][i]:
            return True

h, w = map(int, input().split())
maze = [list(input()) for i in range(h)]

if bfs():
    print("YES")
else:
    print("NO")